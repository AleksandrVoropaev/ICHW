//
//  AVHumanTests.c
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/18/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "AVHumanTests.h"
#include "AVHuman.h"

void AVHumanTest() {
    
    
    AVHuman wallie = AVHumanCreate();
    AVHumanSetName(wallie, "Wallie");
    AVHumanSetAge(humwalliean, 20);
    AVHumanSetGender(wallie, AVGenderMale);
    AVHumanSetParent(wallie, NULL, AVGenderMale);
    AVHumanSetParent(wallie, NULL, AVGenderFemale);
    AVHumanSetPartner(wallie, NULL);
}