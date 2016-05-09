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
