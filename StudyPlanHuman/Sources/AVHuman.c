//
//  AVHuman.c
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/4/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <assert.h>

#include "AVHuman.h"

//void *__AVObjectCreate(size_t objectSize, AVObjectDeallocatorCallback deallocateCallback) {
//    assert(0 != objectSize);
//    
//    AVObject *object = calloc(1, objectSize);
//    
//    assert(NULL != object);
//    
//    object->referenceCount = 1;
//    object->_deallocator = deallocateCallback;
//    
//    return object;
//}
//
//void *AVObjectRetain(void *object) {
//    if (NULL != object) {
//        ((AVObject *)object)->referenceCount++;
//    }
//    
//    return object;
//}
//
//void AVObjectRelease(void *object) {
//    if (NULL != object) {
//        uint64_t count = ((AVObject *)object)->referenceCount - 1;
//        ((AVObject *)object)->referenceCount = count;
//        if (0 == count) {
//            ((AVObject *)object)->_deallocator(object);
//        }
//    }
//}
//
//uint64_t AVObjectGetReferenceCount(void *object) {
//    return object ? ((AVObject *)object)->referenceCount : 0;
//}
//
//void __AVObjectDeallocate(void *object) {
//    free(object);
//}

#pragma mark -
#pragma mark

static const uint8_t kAVMaxChildrenCount = 20;
static const uint8_t kAVChildNotFound = UINT8_MAX;

void __AVHumanDeallocate(AVHuman *human) {
    __AVObjectDeallocate(human);
}

void *AVHumanCreate() {
    return AVObjectCreateOfType(AVHuman);
}

void AVHumanSetName(AVHuman *human, char *name) {
    if (human) {
        human->_name = name;
    }
}

char *AVHumanGetName(AVHuman *human) {
    if (human) {
        return human->_name;
    }
    
    return "";
}

void AVHumanSetAge(AVHuman *human, uint8_t age) {
    if (human) {
        human->_age = age;
    }
}

uint8_t AVHumanGetAge(AVHuman *human) {
    if (human) {
        return human->_age;
    }
    
    return 0;
}

void AVHumanSetSex(AVHuman *human, bool sex) {
    if (human) {
        human->_sex = sex;
    }
}

AVSex AVHumanGetSex(AVHuman *human) {
    if (human) {
        return human->_sex;
    }
    
    return NULL;
}

void AVHumanChangeChildrenCountWithValue(AVHuman *human, uint8_t value) {
    if (human) {
        human->_childrenCount += value;
    }
}

uint8_t AVHumanGetChildrenCount(AVHuman *human) {
    if (human) {
        return human->_childrenCount;
        
    }
    
    return 0;
}

void AVHumanSetMaritalStatus(AVHuman *human, AVMaritalStatus maritalStatus) {
    if (human) {
        human->_maritalStatus = maritalStatus;
    }
}

AVMaritalStatus AVHumanGetMaritalStatus(AVHuman *human) {
    if (human) {
        return human->_maritalStatus;
    }
    
    return NULL;
}

void AVHumanGetMarried(AVHuman *human, AVHuman *partner) {
    if (human
        && partner
        && human->_maritalStatus != AVIsMarried
        && partner->_maritalStatus != AVIsMarried
        && human->_sex != partner->_sex)
    {
        AVObjectRetain(human);
        AVObjectRetain(partner);
        human->_partner = partner;
        human->_maritalStatus = AVIsMarried;
        partner->_partner = human;
        partner->_maritalStatus = AVIsMarried;
    }
}

void AVHumanGetDivorced(AVHuman *firstPartner, AVHuman *secondPartner) {
    if (firstPartner
        && secondPartner
        && firstPartner->_partner == secondPartner)
    {
        firstPartner->_partner = NULL;
        firstPartner->_maritalStatus = AVIsDivorced;
        secondPartner->_partner = NULL;
        secondPartner->_partner = false;
        AVObjectRelease(firstPartner);
        AVObjectRelease(secondPartner);
    }
}

void AVHumanAddChild(AVHuman *human, AVHuman *child) {
    if (human && child) {
        human->_children[human->_childrenCount] = child;
        AVHumanChangeChildrenCountWithValue(human, 1);
    }
}

void AVHumanAddChildAtIndex(AVHuman *human, AVHuman *child, uint8_t index) {
    if (human && child) {
        human->_children[index] = child;
    }
}

uint8_t AVHumanGetChildIndex(AVHuman *human, AVHuman *child) {
    unsigned short thisChildIndex = kAVChildNotFound;
    if (human && child) {
        for (unsigned short index = 0; index < kAVMaxChildrenCount; index++) {
            if (human->_children[index] == child) {
                thisChildIndex = index;
            }
        }
    }
    
    return thisChildIndex;
}

void AVHumanDeleteChild(AVHuman *human,AVHuman *child) {
    if (human && child) {
        uint8_t  thisChildIndex = AVHumanGetChildIndex(human, child);
        
        if (kAVChildNotFound != thisChildIndex) {
            for (unsigned short index = thisChildIndex; index < kAVMaxChildrenCount - 1; index++) {
                human->_children[index] = human->_children[index + 1];
            }
            
            AVHumanChangeChildrenCountWithValue(human, -1);
        }
    }
}

void AVHumanSetMother(AVHuman *human, AVHuman *mother) {
    if (human
        && mother
        && mother->_sex == AVFemale
        && mother->_children[mother->_childrenCount] == human)
    {
        human->_mother = mother;
        AVObjectRetain(mother);
        AVObjectRetain(human);
        AVHumanAddChild(mother, human);
    }
}



void AVHumanUnSetMother(AVHuman *human, AVHuman *mother) {
    if (human
        && mother
        && human->_mother == mother)
    {
        AVHumanDeleteChild(mother, human);
        AVObjectRelease(human);
        AVObjectRelease(mother);
    }
}

void AVHumanSetFather(AVHuman *human, AVHuman *father) {
    if (human
        && father
        && father->_sex == AVMale
        && father->_children[father->_childrenCount] == human)
    {
        human->_father = father;
        AVObjectRetain(human);
        AVObjectRetain(father);
        AVHumanAddChild(father, human);
    }
}

void AVHumanUnSetFather(AVHuman *human, AVHuman *father) {
    if (human
        && father
        && human->_father == father)
    {
        AVHumanDeleteChild(father, human);
        AVObjectRelease(human);
        AVObjectRelease(father);
    }
}

