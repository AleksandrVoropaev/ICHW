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

ICVarietyOfOptionsToBePrintedAmongMamaPapaOrNewLine ICPrintMamaPapaOptionAccordingToGivenVariable(int value) {
    ICVarietyOfOptionsToBePrintedAmongMamaPapaOrNewLine option;
    
    if (0 == value % 15) {
        option = ICPrintedMamaPapa;
    } else if (0 == value % 3) {
        option = ICPrintedMama;
    } else if (0 == value % 5) {
        option = ICPrintedPapa;
    } else {
        option = ICNothigPrinted;
    }
    
    switch (option) {
        case ICPrintedMamaPapa:
            ICPrintMama();
        case ICPrintedPapa:
            ICPrintPapa();
            break;
        case ICPrintedMama:
            ICPrintMama();
            break;
        default:
            break;
    }
    ICPrintNewLine();
            
    return option;
}
