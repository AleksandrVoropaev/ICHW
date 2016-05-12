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

#include "AVObject.h"

//typedef void (*AVObjectDeallocatorCallback)(void *);
//
//typedef struct {
//    uint64_t referenceCount;
//    AVObjectDeallocatorCallback _deallocator;
//} AVObject;
//
//extern
//void *__AVObjectCreate(size_t objectSize, AVObjectDeallocatorCallback deallocateCallback);
//
//#define AVObjectCreateOfType(type) \
//__AVObjectCreate(sizeof(type), (AVObjectDeallocatorCallback)__##type##Deallocate)
//
//extern
//void *AVObjectRetain(void *object);
//
//extern
//void AVObjectRelease(void *object);
//
//extern
//uint64_t AVGetReferenceCount(void *object);
//
//extern
//void __AVObjectDeallocate(void *object);

typedef struct AVHuman AVHuman;

typedef enum {
    AVMale,
    AVFemale,
} AVSex;

typedef enum {
    AVIsSingle,
    AVIsMarried,
    AVIsDivorced,
} AVMaritalStatus;

struct AVHuman {
    AVObject *_object;
    char *_name;
    short _age;
    AVSex _sex;
    short _childrenCount;
    AVMaritalStatus _maritalStatus;
    AVHuman *_partner;
    AVHuman *_mother;
    AVHuman *_father;
    AVHuman *_children[20];
};

#endif /* AVHuman_h */
