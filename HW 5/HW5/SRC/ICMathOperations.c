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
        decision = ICMama;
    } else if (0 == value % 5) {
        decision = ICPapa;
    }
    
    if (0 == value % 15) {
        decision = ICMamaPapa;
    }
    
    switch (decision) {
        case ICMama:
            ICPrintMama();
            ICPrintNewLine();
            break;
        case ICPapa:
            ICPrintPapa();
            ICPrintNewLine();
            break;
        case ICMamaPapa:
            ICPrintMama();
            ICPrintPapa();
            ICPrintNewLine();
            break;
        default:
            break;
    }
}