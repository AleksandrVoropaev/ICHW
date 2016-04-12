//
//  ICMathOperations.c
//  HW5
//
//  Created by Aleksandr Voropaev on 4/8/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>

#include "ICMathOperations.h"
#include "ICPrintOperations.h"

bool ICAndOperation(bool firstValue, bool secondValue) {
    bool result = firstValue && secondValue;
    
    return result;
}

bool ICOrOperation(bool firstValue, bool secondValue) {
    bool result = firstValue || secondValue;
    
    return result;
}

ICPrintType ICMamaPapaPrintTypePrintWithVariable(int value) {
    ICPrintType printType = ICPrintedNothig;
    
    if (0 == value % 3) {
        printType = ICPrintedMama;
        ICPrintMama();
    }
    
    if (0 == value % 5) {
        printType = ICPrintedPapa;
        ICPrintPapa();
    }
    
    if (0 == value % 15) {
        printType++;
    }
    
    if (printType) {
        ICPrintNewLine();
    }
    
    return printType;
}
