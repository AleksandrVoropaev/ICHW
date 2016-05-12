//
//  AVObject.h
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/12/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef AVObject_h
#define AVObject_h

#include <stdio.h>

typedef void (*AVObjectDeallocatorCallback)(void *);

typedef struct {
    uint64_t referenceCount;
    AVObjectDeallocatorCallback _deallocator;
} AVObject;

extern
void *__AVObjectCreate(size_t objectSize, AVObjectDeallocatorCallback deallocateCallback);

#define AVObjectCreateOfType(type) \
    __AVObjectCreate(sizeof(type), (AVObjectDeallocatorCallback)__##type##Deallocate)

extern
void *AVObjectRetain(void *object);

extern
void AVObjectRelease(void *object);

extern
uint64_t AVGetReferenceCount(void *object);

extern
void __AVObjectDeallocate(void *object);

#endif /* AVObject_h */
