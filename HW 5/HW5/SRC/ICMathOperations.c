//
//  ICMathOperations.c
//  HW5
//
//  Created by Aleksandr Voropaev on 4/8/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>

#include "ICMathOperations.h"

bool ICAndOperation(bool firstValue, bool secondValue) {
    bool result = firstValue && secondValue;
    
    return result;
}

bool ICOrOperation(bool firstValue, bool secondValue) {
    bool result = firstValue || secondValue;
    
    return result;
}
