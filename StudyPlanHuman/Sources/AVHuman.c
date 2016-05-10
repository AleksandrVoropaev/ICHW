//
//  AVHuman.c
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/4/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <assert.h>

#include "AVHuman.h"

void *__AVObjectCreate(size_t objectSize, AVObjectDeallocatorCallback deallocateCallback) {
    assert(0 != objectSize);
    
    AVObject *object = calloc(1, objectSize);
    
    assert(NULL != object);
    
    object->referenceCount = 1;
    object->_deallocator = deallocateCallback;
    
    return object;
}

void *AVObjectRetain(void *object) {
    if (NULL != object) {
        ((AVObject *)object)->referenceCount++;
    }
    
    return object;
}

void AVObjectRelease(void *object) {
    if (NULL != object) {
        uint64_t count = ((AVObject *)object)->referenceCount - 1;
        ((AVObject *)object)->referenceCount = count;
        if (0 == count) {
            ((AVObject *)object)->_deallocator(object);
        }
    }
}

uint64_t AVObjectGetReferenceCount(void *object) {
    return object ? ((AVObject *)object)->referenceCount : 0;
}

void __AVObjectDeallocate(void *object) {
    free(object);
}

//human

void __AVHumanDeallocate(AVHuman *human) {
    __AVObjectDeallocate(human);
}

void *AVHumanCreate() {
    return AVObjectCreateOfType(AVHuman);
}

void AVHumanSetName(AVHuman *human, char *name) {
    if (human) {
        human->name = name;
    }
}

void AVHumanSetAge(AVHuman *human, short age) {
    if (human) {
        human->age = age;
    }
}

void AVHumanSetSex(AVHuman *human, bool isMale) {
    if (human) {
        human->isMale = isMale;
    }
}

void AVHumanChildrenCountIncrese(AVHuman *human) {
    if (human) {
        human->childrenCount++;
    }
}

void AVHumanChildrenCountDecrese(AVHuman *human) {
    if (human) {
        human->childrenCount--;
    }
}

void AVHumanGetMarried(AVHuman *human, AVHuman *partner) {
    if (human
            && partner
            && !human->isMarried
            && !partner->isMarried
            && human->isMale != partner->isMale) {
        human->partner = partner;
        human->isMarried = true;
        partner->partner = human;
        partner->isMarried = true;
    }
}

void AVHumanGetDivorced(AVHuman *firstPartner, AVHuman *secondPartner) {
    if (firstPartner && secondPartner && firstPartner->partner == secondPartner) {
        firstPartner->partner = NULL;
        firstPartner->isMarried = false;
        secondPartner->partner = NULL;
        secondPartner->partner = false;
    }
}

void AVHumanAddChildren(AVHuman *human, AVHuman *children) {
    if (human && children) {
        human->childrens[human->childrenCount] = children;
        AVHumanChildrenCountIncrese(human);
    }
}

void AVHumanSetMother(AVHuman *human, AVHuman *mother) {
    if (human
            && mother
            && !mother->isMale
            && mother->childrens[mother->childrenCount] == human) {
        human->mother = mother;
    }
}

void AVHumanSetFather(AVHuman *human, AVHuman *father) {
    if (human
            && father
            && father->isMale
            && father->childrens[father->childrenCount] == human) {
        human->father = father;
    }
}
