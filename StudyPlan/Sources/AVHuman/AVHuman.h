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
    AVGenderUndefined,
    AVGenderMale,
    AVGenderFemale,
} AVGender;

struct AVHuman {
    AVObject _object;
    
    char *_name;
    short _age;
    AVGender _gender;
    short _childrenCount;
    
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
#pragma mark Accessors

void AVHumanSetName(AVHuman *human, char *name);
char *AVHumanGetName(AVHuman *human);

void AVHumanSetAge(AVHuman *human, uint8_t age);
uint8_t AVHumanGetAge(AVHuman *human);

void AVHumanSetGender(AVHuman *human, AVGender gender);
AVGender AVHumanGetGender(AVHuman *human);

#pragma mark -
#pragma mark gender relations

bool AVHumanHasDifferentGendreWithPartner(AVHuman *human, AVHuman *partner);

void AVHumanGetDivorced(AVHuman *human);
void AVHumanGetMarried(AVHuman *human, AVHuman *partner);

AVHuman *AVHumanGetPartner(AVHuman *human);

#pragma mark -
#pragma mark Child

void AVHumanSetChildAtIndex(AVHuman *human, AVHuman *child, uint8_t index);

AVHuman *AVHumanAddChild(AVHuman *father, AVHuman *mother);
AVHuman *AVHumanGetChildAtIndex(AVHuman *human, uint8_t index);

AVHuman *AVHumanGetMother(AVHuman *human);

AVHuman *AVHumanGetFather(AVHuman *human);

//void AVHumanGiveBirthToChild(AVHuman *father, AVHuman *mother, AVHuman *child);

void AVHumanRemoveChildren(AVHuman *human);
void AVHumanRemoveChildAtIndex(AVHuman *human, uint8_t index);
void AVHumanRemoveChild(AVHuman *human, AVHuman *child);

uint8_t AVHumanGetChildIndex(AVHuman *human, AVHuman *child);
void AVHumanReorderChildrenStartingWithIndex(AVHuman *human, uint8_t index);

#endif /* AVHuman_h */
