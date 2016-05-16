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
    AVHumanDeleteAllChildren(human);
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
        strcpy(human->_name, name);
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

void AVHumanSetWeakPartner(AVHuman *human, AVHuman *partner) {
    if (AVHumanHasDifferentGendreWithPartner(human, partner)) {
        human->_partner = partner;
    }
}

void AVHumanSetStrongPartner(AVHuman *human, AVHuman *partner) {
    if (AVHumanHasDifferentGendreWithPartner(human, partner)) {
        AVObjectRelease(human);
        human->_partner = partner;
        AVHumanSetWeakPartner(partner, human);
        AVObjectRetain(human);
    }
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

void AVHumanDeleteChildAtIndex(AVHuman *human, uint8_t index) {
    if (human) {
        human->_children[index] = 0;
        AVObjectRelease(human);
    }
}

void AVHumanDeleteAllChildren(AVHuman *human) {
    if (human) {
        for (uint8_t index = 0; index < AVHumanGetChildrenCount(human); index++) {
            AVHumanDeleteChildAtIndex(human, index);
        }
    }
}

void AVHumanSetMother(AVHuman *human, AVHuman *mother) {
    if (human && mother) {
        human->_mother = mother;
        AVObjectRetain(mother);
    }
}

void AVHumanUnSetMother(AVHuman *human) {
    if (human) {
        AVObjectRelease(human->_mother);
        human->_mother = 0;
    }
}

void AVHumanSetFather(AVHuman *human, AVHuman *father) {
    if (human && father) {
        human->_father = father;
        AVObjectRetain(father);
    }
}

void AVHumanUnSetFather(AVHuman *human) {
    if (human) {
        AVObjectRelease(human->_father);
        human->_father = 0;
    }
}
