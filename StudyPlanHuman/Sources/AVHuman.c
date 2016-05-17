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
#pragma mark human create

void __AVHumanDeallocate(AVHuman *human) {
    AVMale == AVHumanGetGender(human) ? AVHumanStrongPartnerGetsDivorced(human) : AVHumanWeakPartnerGetsDivorced(human);
    AVHumanRemoveAllChildren(human);
    AVHumanUnSetFather(human);
    AVHumanUnSetMother(human);
    __AVObjectDeallocate(human);
}

void *AVHumanCreate() {
    return AVObjectCreateOfType(AVHuman);
}

#pragma mark -
#pragma mark setters and getters

void AVHumanSetName(AVHuman *human, char *name) {
    if (human && human->_name != name) {
        human->_name = strdup(name);
        free(name);
    }
}

char *AVHumanGetName(AVHuman *human) {
    return human ? human->_name : NULL;
}

void AVHumanSetAge(AVHuman *human, uint8_t age) {
    human->_age = human ? age : kAVNotFound;
}

uint8_t AVHumanGetAge(AVHuman *human) {
    return human ? human->_age : kAVNotFound;
}

void AVHumanSetGendre(AVHuman *human, AVGender gendre) {
    human->_gender = human ? gendre : AVNotDefined;
}

AVGender AVHumanGetGender(AVHuman *human) {
    return human ? human->_gender : AVNotDefined;
}

void AVHumanSetChildrenCountWithValue(AVHuman *human, short value) {
    human->_childrenCount = human ? value : 0;
}

uint8_t AVHumanGetChildrenCount(AVHuman *human) {
    return human ? human->_childrenCount : kAVNotFound;
}

void AVHumanSetMaritalStatus(AVHuman *human, AVMaritalStatus maritalStatus) {
    human->_maritalStatus = human ? maritalStatus : AVNotIdentified;
}

AVMaritalStatus AVHumanGetMaritalStatus(AVHuman *human) {
    return human ? human->_maritalStatus : AVNotIdentified;
}

#pragma mark -
#pragma mark gender relations

bool AVHumanHasDifferentGendreWithPartner(AVHuman *human, AVHuman *partner) {
    if (human
        && partner
        && human->_gender != partner->_gender)
    {
        return true;
    }
    
    return false;
}

void AVHumanSetPartner(AVHuman *human, AVHuman *partner) {
    if (AVHumanHasDifferentGendreWithPartner(human, partner)) {
        if (AVMale == human->_gender) {
            AVHumanSetStrongPartner(human, partner);
            AVHumanSetWeakPartner(partner, human);
        } else {
            AVHumanSetStrongPartner(partner, human);
            AVHumanSetWeakPartner(human, partner);
        }
    }
}

void AVHumanSetWeakPartner(AVHuman *human, AVHuman *partner) {
    human->_partner = partner;
    human->_maritalStatus = AVIsMarried;
}

void AVHumanSetStrongPartner(AVHuman *human, AVHuman *partner) {
    AVObjectRelease(partner);
    human->_partner = partner;
    human->_maritalStatus = AVIsMarried;
    AVObjectRetain(partner);
}

AVHuman *AVHumanGetPartner(AVHuman *human) {
    if (human) {
        return human->_partner;
    }
    
    return NULL;
}

void AVHumanStrongPartnerGetsDivorced(AVHuman *human) {
    if (human && human->_partner)
    {
        human->_partner->_partner = NULL;
        human->_partner->_maritalStatus = AVIsDivorced;
        human->_partner = NULL;
        human->_maritalStatus = AVIsDivorced;
        AVObjectRelease(human);
    }
}

void AVHumanWeakPartnerGetsDivorced(AVHuman *human) {
    if (human) {
        human->_partner = NULL;
        human->_maritalStatus = AVIsDivorced;
    }
}

#pragma mark -
#pragma mark Child

uint8_t AVHumanGetChildIndex(AVHuman *human, AVHuman *child) {
    uint8_t thisChildIndex = kAVNotFound;
    if (human && child) {
        for (uint8_t index = 0; index < kAVMaxChildrenCount; index++) {
            if (human->_children[index] == child) {
                thisChildIndex = index;
            }
        }
    }
    
    return thisChildIndex;
}

void AVHumanAddChildAtIndex(AVHuman *human, AVHuman *child, uint8_t index) {
    if (human && child) {
        human->_children[index] = child;
        AVObjectRetain(human);
    }
}

void AVHumanRemoveChildAtIndex(AVHuman *human, uint8_t index) {
    if (human) {
        human->_children[index] = NULL;
        human->_childrenCount--;
        AVObjectRelease(human);
        AVHumanResortChildrenArrayWithIndex(human, index);
    }
}

void AVHumanRemoveAllChildren(AVHuman *human) {
    if (human) {
        for (uint8_t index = 0; index < AVHumanGetChildrenCount(human); index++) {
            AVHumanRemoveChildAtIndex(human, index);
        }
    }
}

void AVHumanResortChildrenArrayWithIndex(AVHuman *human, uint8_t index) {
    if (human) {
        for (uint8_t count = index; count < kAVMaxChildrenCount - 1; count++) {
            human->_children[count] = human->_children[count + 1];
        }
    }
}

void AVHumanSetParent(AVHuman *human, AVHuman *parent) {
    if (human && AVMale == parent->_gender) {
        AVHumanSetFather(human, parent);
    } else if (human && AVFemale == parent->_gender) {
        AVHumanSetMother(human, parent);
    }
}

void AVHumanSetMother(AVHuman *human, AVHuman *mother) {
    if (human) {
        AVHumanRemoveChildAtIndex(mother, AVHumanGetChildIndex(human->_mother, human));
        AVObjectRelease(human);
        human->_mother = mother;
        AVHumanAddChildAtIndex(mother, human, AVHumanGetChildIndex(mother, human));
        AVObjectRetain(human);
    }
}

void AVHumanSetFather(AVHuman *human, AVHuman *father) {
    if (human) {
        AVHumanRemoveChildAtIndex(father, AVHumanGetChildIndex(human->_father, human));
        AVObjectRelease(human);
        human->_mother = father;
        AVHumanAddChildAtIndex(father, human, AVHumanGetChildIndex(father, human));
        AVObjectRetain(human);
    }
}
