//
//  ICBoolCheck.c
//  HW5
//
//  Created by Aleksandr Voropaev on 4/7/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#include "ICBoolCheck.h"

void ICPrintBoolValue(bool value) {
    //printf("The Bool is ");
    (value) ? printf("True\n") : printf("False\n");
}
