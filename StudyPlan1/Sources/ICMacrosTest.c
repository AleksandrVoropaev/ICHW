//
//  ICMacrosTest.c
//  StudyPlan1
//
//  Created by Aleksandr Voropaev on 4/25/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "ICMacrosTest.h"

ICGenerateFunctionWithTypeAndSpecifier(float, f)

void ICRunMacros() {
    float value = 11.1; // test value
    ICRunGeneratedFunction(float, value);
}