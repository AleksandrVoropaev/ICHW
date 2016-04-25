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

#define ICMacrosGenerateFunction(type, argument) \
        #type ICOutput_#type(void) { \
            #type variable = argument; \
            return variable; \
        }

#define ICPrintGeneratedFunctionResult(type, argument, specificator) \
        ICMacrosGenerateFunction(#type, #argument); \
        #type result = ICOutput_#type(); \
        printf("%" #specificator, result)

#endif /* ICMacrosTest_h */
