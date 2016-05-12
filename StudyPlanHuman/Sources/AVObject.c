//
//  AVObject.c
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/12/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>

#include "AVObject.h"

void *__AVObjectCreate(size_t objectSize, AVObjectDeallocatorCallback deallocateCallback) {
    assert(objectSize);
    
    AVObject *object = calloc(1, objectSize);
    
    assert(object);
    
    object->referenceCount = 1;
    object->_deallocator = deallocateCallback;
    
    return object;
}

void *AVObjectRetain(void *object) {
    if (object) {
        ((AVObject *)object)->referenceCount++;
    }
    
    return object;
}

void AVObjectRelease(void *address) {
    AVObject *object = address;
    if (object) {
        uint64_t count = object->referenceCount - 1;
        object->referenceCount = count;
        if (0 == count) {
            object->_deallocator(object);
        }
    }
}

uint64_t AVObjectGetReferenceCount(void *object) {
    return object ? ((AVObject *)object)->referenceCount : 0;
}

void __AVObjectDeallocate(void *object) {
    if (object) {
        free(object);
    }
}
