//
//  AVHuman.h
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/4/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef AVHuman_h
#define AVHuman_h

#include <stdlib.h>
#include <stdbool.h>

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

typedef struct AVHuman AVHuman;

struct AVHuman {
    char *name;
    short age;
    bool isMale;
    short childrenCount;
    bool isMarried;
    AVHuman *partner;
    AVHuman *mother;
    AVHuman *father;
    AVHuman *childrens[20];
};

#endif /* AVHuman_h */
