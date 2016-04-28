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
    ICPrintRandomStructOffset();
    ICPrintRandomStructSizeof();
    ICPrintSortedStructOffset();
    ICPrintSortedStructSizeof();
    ICPrintStructWithBitfieldOffset();
    ICPrintStructWithBitfieldSizeof();
    
    ICPrintBitfield();
    uint8_t byte = 5;
    ICByteOutput(byte);
    puts("");
    uint16_t twobytes = 5;
    ICVariableBitOutput(&twobytes, sizeof(twobytes));
    
    printf("%s\n", ICBigLittleEndianTest());
}