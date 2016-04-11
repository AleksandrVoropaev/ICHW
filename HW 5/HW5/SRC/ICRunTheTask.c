//
//  ICRunTheTask.c
//  HW5
//
//  Created by Aleksandr Voropaev on 4/8/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>

#include "ICRunTheTask.h"
#include "ICMathOperations.h"

void ICRunBoolCompare() {
    printf("true && true = %s\n", ICAndOperation(true, true) ? "true" : "false");
    printf("true && false = %s\n", ICAndOperation(true, false) ? "true" : "false");
    printf("false && true = %s\n", ICAndOperation(false, true) ? "true" : "false");
    printf("false && false = %s\n", ICAndOperation(false, false) ? "true" : "false");
    
    printf("true || true = %s\n", ICOrOperation(true, true) ? "true" : "false");
    printf("true || false = %s\n", ICOrOperation(true, false) ? "true" : "false");
    printf("false || true = %s\n", ICOrOperation(false, true) ? "true" : "false");
    printf("false || false = %s\n", ICOrOperation(false, false) ? "true" : "false");
}
