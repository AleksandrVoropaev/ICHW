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

typedef struct AVHuman AVHuman;

typedef enum {
    AVMale,
    AVFemale,
    AVNotDefined,
} AVGender;

typedef enum {
    AVIsSingle,
    AVIsMarried,
    AVIsDivorced,
    AVNotIdentified,
} AVMaritalStatus;

struct AVHuman {
    AVObject _object;
    
    char *_name;
    short _age;
    AVGender _gender;
    short _childrenCount;
    AVMaritalStatus _maritalStatus;
    
    AVHuman *_partner;
    AVHuman *_mother;
    AVHuman *_father;
    AVHuman *_children[20];
};

#pragma mark -
#pragma mark human create

void __AVHumanDeallocate(AVHuman *human);
void *AVHumanCreate();

#pragma mark -
#pragma mark setters and getters

void AVHumanSetName(AVHuman *human, char *name);
char *AVHumanGetName(AVHuman *human);

void AVHumanSetAge(AVHuman *human, uint8_t age);
uint8_t AVHumanGetAge(AVHuman *human);

void AVHumanSetGendre(AVHuman *human, AVGender gendre);
AVGender AVHumanGetGender(AVHuman *human);

void AVHumanSetChildrenCountWithValue(AVHuman *human, short value);
uint8_t AVHumanGetChildrenCount(AVHuman *human);

void AVHumanSetMaritalStatus(AVHuman *human, AVMaritalStatus maritalStatus);
AVMaritalStatus AVHumanGetMaritalStatus(AVHuman *human);

#pragma mark -
#pragma mark gender relations

bool AVHumanHasDifferentGendreWithPartner(AVHuman *human, AVHuman *partner);

void AVHumanSetPartner(AVHuman *human, AVHuman *partner);
void AVHumanSetWeakPartner(AVHuman *human, AVHuman *partner);
void AVHumanSetStrongPartner(AVHuman *human, AVHuman *partner);
AVHuman *AVHumanGetPartner(AVHuman *human);

void AVHumanStrongPartnerGetsDivorced(AVHuman *human);
void AVHumanWeakPartnerGetsDivorced(AVHuman *human);

#pragma mark -
#pragma mark Child

uint8_t AVHumanGetChildIndex(AVHuman *human, AVHuman *child);
void AVHumanAddChildAtIndex(AVHuman *human, AVHuman *child, uint8_t index);
void AVHumanRemoveChildAtIndex(AVHuman *human, uint8_t index);
void AVHumanRemoveAllChildren(AVHuman *human);
void AVHumanResortChildrenArrayWithIndex(AVHuman *human, uint8_t index);

void AVHumanSetParent(AVHuman *human, AVHuman *parent);
void AVHumanSetMother(AVHuman *human, AVHuman *mother);
void AVHumanSetFather(AVHuman *human, AVHuman *father);

#endif /* AVHuman_h */
