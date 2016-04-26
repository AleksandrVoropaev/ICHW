//
//  ICMacrosTest.h
//  StudyPlan1
//
//  Created by Aleksandr Voropaev on 4/25/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef ICMacrosTest_h
#define ICMacrosTest_h

#include <stdio.h>

#define ICGenerateFunctionWithTypeAndSpecifier(type, specifier) \
    void ICOutput_##type(type variable) { \
        printf(#type " value is %" #specifier "\n\n", variable); \
    }

#define ICRunGeneratedFunction(type, argument) \
    type variable = argument; \
    ICOutput_##type(variable)

void ICRunMacros();

#endif /* ICMacrosTest_h */
