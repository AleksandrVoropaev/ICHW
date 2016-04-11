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

void ICDecisionMamaPapa(int value) {
    ICMamaPapaOption decision;
    if (0 == value % 3) {
        decision = mama;
    } else if (0 == value % 5) {
        decision = papa;
    } else {
        decision = none;
    }
    
    if (0 == value % 15) {
        decision = mamapapa;
    }
    
    switch (decision) {
        case mama:
            ICPrintMama();
            ICPrintNewLine();
            break;
        case papa:
            ICPrintPapa();
            ICPrintNewLine();
            break;
        case mamapapa:
            ICPrintMama();
            ICPrintPapa();
            ICPrintNewLine();
            break;
        default:
            break;
    }
}