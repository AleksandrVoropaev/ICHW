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

void __AVHumanDeallocate(AVHuman *human);

void *AVHumanCreate();

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

bool AVHumanHasDifferentGendreWithPartner(AVHuman *human, AVHuman *partner);

void AVHumanSetWeakPartner(AVHuman *human, AVHuman *partner);
void AVHumanSetStrongPartner(AVHuman *human, AVHuman *partner);
AVHuman *AVHumanGetPartner(AVHuman *human);
void AVHumanStrongPartnerGetsDivorced(AVHuman *human);
void AVHumanWeakPartnerGetsDivorced(AVHuman *human);

uint8_t AVHumanGetChildIndex(AVHuman *human, AVHuman *child);
void AVHumanAddChildAtIndex(AVHuman *human, AVHuman *child, uint8_t index);
void AVHumanDeleteChildAtIndex(AVHuman *human, uint8_t index);
void AVHumanDeleteAllChildren(AVHuman *human);
void AVHumanSetMother(AVHuman *human, AVHuman *mother);
void AVHumanUnSetMother(AVHuman *human);
void AVHumanSetFather(AVHuman *human, AVHuman *father);
void AVHumanUnSetFather(AVHuman *human);

#endif /* AVHuman_h */
