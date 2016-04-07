//
//  ICVariablesPrint.c
//  HW4
//
//  Created by Aleksandr Voropaev on 4/7/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "ICVariablesPrint.h"
#include "stdio.h"

void ICVariablesPrint(int intValue, float floatValue, char charValue, char string[3]) {
    printf("Integer - %d\n", intValue);
    printf("Float - %f\n", floatValue);
    printf("Char - %c\n", charValue);
    printf("String - %s \n", string);
}
