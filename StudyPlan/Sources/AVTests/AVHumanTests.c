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
    AVHuman *abraham = AVHumanCreate();
    AVHumanSetName(abraham, "Abraham");
    AVHumanSetAge(abraham, 60);
    AVHumanSetGender(abraham, AVGenderMale);
    
    AVHuman *mona = AVHumanCreate();
    AVHumanSetName(mona, "Mona");
    AVHumanSetAge(mona, 60);
    AVHumanSetGender(mona, AVGenderFemale);
    
    AVHumanGetMarried(abraham, mona);
    AVHumanGetMarried(mona, abraham);
    
    AVHuman *homer = AVGiveBirthToChild(abraham);
    AVHumanSetName(homer, "Homer");
    AVHumanSetAge(homer, 40);
    AVHumanSetGender(homer, AVGenderMale);
    
    AVHuman *marge = AVHumanCreate();
    AVHumanSetName(marge, "Marge");
    AVHumanSetAge(marge, 40);
    AVHumanSetGender(marge, AVGenderFemale);

    AVHumanGetMarried(homer, marge);
    AVHumanGetMarried(marge, homer);
    
    AVHuman *bart = AVGiveBirthToChild(homer);
    AVHumanSetName(bart, "Bart");
    AVHumanSetAge(bart, 15);
    AVHumanSetGender(bart, AVGenderMale);
    
    AVHuman *lisa = AVGiveBirthToChild(marge);
    AVHumanSetName(lisa, "Lisa");
    AVHumanSetAge(lisa, 10);
    AVHumanSetGender(lisa, AVGenderFemale);
    
    AVHumanRemoveChild(homer, bart);
    AVHumanRemoveChild(homer, lisa);
    
    AVHumanRemoveChildren(marge);
    
    AVHumanRemoveChildren(abraham);
    AVHumanRemoveChildren(mona);
    
    AVHumanGetDivorced(homer);
    AVHumanGetDivorced(mona);
    
    AVObjectRelease(abraham);
    AVObjectRelease(mona);
    AVObjectRelease(marge);
}
