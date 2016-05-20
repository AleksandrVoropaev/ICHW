//
//  AVHuman.c
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/4/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <assert.h>
#include <string.h>

#include "AVHuman.h"

#pragma mark -
#pragma mark constants

static const uint8_t kAVMaxChildrenCount = 20;
static const uint8_t kAVNotFound = UINT8_MAX;

#pragma mark -
#pragma mark Private

void AVHumanSetChildrenCountAddValue(AVHuman *human, short value);
void AVHumanSetChildrenCountWithValue(AVHuman *human, short value);
uint8_t AVHumanGetChildrenCount(AVHuman *human);

void AVHumanSetWeakPartner(AVHuman *human, AVHuman *partner);
void AVHumanSetStrongPartner(AVHuman *human, AVHuman *partner);
void AVHumanSetPartner(AVHuman *human, AVHuman *partner);

void AVHumanSetParent(AVHuman *human, AVHuman *parent, AVGender parentGender);
void AVHumanSetMother(AVHuman *human, AVHuman *mother);
void AVHumanSetFather(AVHuman *human, AVHuman *father);

#pragma mark -
#pragma mark human create

void __AVHumanDeallocate(AVHuman *human) {
    AVHumanSetName(human, NULL);
    AVHumanSetAge(human, 0);
    AVHumanSetGender(human, AVGenderUndefined);
    AVHumanRemoveChildren(human);
    AVHumanSetParent(human, NULL, AVGenderMale);
    AVHumanSetParent(human, NULL, AVGenderFemale);
    AVHumanSetPartner(human, NULL);
    __AVObjectDeallocate(human);
}

void *AVHumanCreate() {
    return AVObjectCreateWithType(AVHuman);
}

#pragma mark -
#pragma mark Accessors

void AVHumanSetName(AVHuman *human, char *name) {
    if (NULL != human && name != human->_name) {
        if (human->_name) {
            free(human->_name);
            human->_name = NULL;
        }
        
        if (name) {
            human->_name = strdup(name);
        }
    }
}

char *AVHumanGetName(AVHuman *human) {
    return human ? human->_name : NULL;
}

void AVHumanSetAge(AVHuman *human, uint8_t age) {
    if (human) {
        human->_age = age;
    } else {
        human->_age = kAVNotFound;
    }
}

uint8_t AVHumanGetAge(AVHuman *human) {
    return human ? human->_age : kAVNotFound;
}

void AVHumanSetGender(AVHuman *human, AVGender gender) {
    if (human) {
        human->_gender = gender;
    } else {
        human->_gender = AVGenderUndefined;
    }
}

AVGender AVHumanGetGender(AVHuman *human) {
    return human ? human->_gender : AVGenderUndefined;
}

void AVHumanSetChildrenCountAddValue(AVHuman *human, short value) {
    if (human) {
        AVHumanSetChildrenCountWithValue(human, AVHumanGetChildrenCount(human) + value);
    }
}

void AVHumanSetChildrenCountWithValue(AVHuman *human, short value) {
    if (human) {
        human->_childrenCount = value;
    } else {
        human->_childrenCount = 0;
    }
}

uint8_t AVHumanGetChildrenCount(AVHuman *human) {
    return human ? human->_childrenCount : kAVNotFound;
}

#pragma mark -
#pragma mark gender relations

bool AVHumanHasDifferentGenderWithPartner(AVHuman *human, AVHuman *partner) {
    return (human && partner && AVHumanGetGender(human) != AVHumanGetGender(partner));
}

void AVHumanSetWeakPartner(AVHuman *human, AVHuman *partner) {
    if (human) {
        human->_partner = partner;
    }
}

void AVHumanSetStrongPartner(AVHuman *human, AVHuman *partner) {
    if (human) {
        AVObjectRelease(human->_partner);
        human->_partner = partner;
        AVObjectRetain(partner);
    }
}

void AVHumanSetPartner(AVHuman *human, AVHuman *partner) {
    if (human) {
        if (AVGenderMale == AVHumanGetGender(human)) {
            AVHumanSetStrongPartner(human, partner);
        } else {
            AVHumanSetWeakPartner(human, partner);
        }
    }
}

void AVHumanGetDivorced(AVHuman *human) {
    AVHumanSetPartner(human->_partner, NULL);
    AVHumanSetPartner(human, NULL);
}

void AVHumanGetMarried(AVHuman *human, AVHuman *partner) {
    if (AVHumanHasDifferentGenderWithPartner(human, partner)
        && human != partner)
    {
        AVHumanGetDivorced(human);
        AVHumanGetDivorced(partner);
        
        AVHumanSetPartner(human, partner);
        AVHumanSetPartner(partner, human);
    }
}

AVHuman *AVHumanGetPartner(AVHuman *human) {
    return human ? human->_partner : NULL;
}

#pragma mark -
#pragma mark Child

void AVHumanSetChildAtIndex(AVHuman *human, AVHuman *child, uint8_t index) {
    if (human) {
        AVObjectRelease(human->_children[index]);
        human->_children[index] = child;
        AVObjectRetain(human->_children[index]);
    }
}

void AVHumanAddChild(AVHuman *human, AVHuman *child) {
    if (human
        && human != child
        && kAVNotFound == AVHumanGetChildIndex(human, child)
        && kAVMaxChildrenCount >= AVHumanGetChildrenCount(human))
    {
        AVHumanSetChildAtIndex(human, child, human->_childrenCount);
        AVHumanSetChildrenCountAddValue(human, 1);
        AVHumanSetParent(child, human, AVHumanGetGender(human));
    }
}

AVHuman *AVHumanGetChildAtIndex(AVHuman *human, uint8_t index) {
    return human ? human->_children[index] : NULL;
}

void AVHumanSetParent(AVHuman *human, AVHuman *parent, AVGender parentGender) {
    if (!human) {
        return;
    }
    
    #define AVSwitchDefault(expression) \
        default: expression;
    
    #define AVSwitchDefaultBreak AVSwitchDefault({})
    
    #define AVSwitchCase(value, expression) \
        case value: expression; \
        break;
    
    switch (parentGender) {
        AVSwitchCase(AVGenderMale, AVHumanSetFather(human, parent));
        AVSwitchCase(AVGenderFemale, AVHumanSetMother(human, parent));
        AVSwitchDefaultBreak;
    }
    
    #undef AVSwitchCase
}

void AVHumanSetMother(AVHuman *human, AVHuman *mother) {
    if (human) {
        human->_mother = mother;
    }
}

AVHuman *AVHumanGetMother(AVHuman *human) {
    return human ? human->_mother : NULL;
}

void AVHumanSetFather(AVHuman *human, AVHuman *father) {
    if (human) {
        human->_father = father;
    }
}
AVHuman *AVHumanGetFather(AVHuman *human) {
    return human ? human->_father : NULL;
}

void AVHumanRemoveChildren(AVHuman *human) {
    if (human) {
        uint8_t iterationsValue = AVHumanGetChildrenCount(human);
        for (uint8_t index = 0; index < iterationsValue; index++) {
            AVHumanRemoveChildAtIndex(human, iterationsValue - index -1);
        }
    }
}

void AVHumanRemoveChildAtIndex(AVHuman *human, uint8_t index) {
    if (human) {
        AVHumanSetChildAtIndex(human, NULL, index);
        AVHumanSetChildrenCountAddValue(human, -1);
        AVHumanReorderChildrenStartingWithIndex(human, index);
    }
}

uint8_t AVHumanGetChildIndex(AVHuman *human, AVHuman *child) {
    uint8_t result = kAVNotFound;
    if (human && child) {
        for (uint8_t index = 0; index < kAVMaxChildrenCount; index++) {
            if (human->_children[index] == child) {
                result = index;
            }
        }
    }
    
    return result;
}

void AVHumanReorderChildrenStartingWithIndex(AVHuman *human, uint8_t index) {
    if (human) {
        uint8_t iterationsValue = AVHumanGetChildrenCount(human);
        for (uint8_t count = index; count < iterationsValue - 1; count++) {
            human->_children[count] = human->_children[count + 1];
        }
    }
}
