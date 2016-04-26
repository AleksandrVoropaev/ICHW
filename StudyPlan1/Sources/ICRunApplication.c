//
//  ICRunApplication.c
//  StudyPlan1
//
//  Created by Aleksandr Voropaev on 4/14/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "ICRunApplication.h"
#include "ICMathFunctions.h"
#include "ICPrintFunctions.h"
#include "ICMacrosTest.h"
#include "ICBitfieldTest.h"

void ICRunAplication() {
    ICPrintSize();
    ICRunMacros();
    ICPrintOffsetOfStruct();
    ICPrintSizeOfStruct();
    ICPrintOffsetOfOptimizedStruct();
    ICPrintSizeOfOptimizedStruct();
}