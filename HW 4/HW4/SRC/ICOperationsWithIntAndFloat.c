//
//  ICOperationsWithIntAndFloat.c
//  HW4
//
//  Created by Aleksandr Voropaev on 4/7/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "ICOperationsWithIntAndFloat.h"

void ICIntAndFloat() {
    int intValue = 1;
    int secondIntValue = 2;
    float floatValue = 1.2;
    printf("int/float %f\n", intValue/floatValue);
    printf("float/int %f\n", floatValue/intValue);
    printf("int*float %f\n", intValue*floatValue);
    printf("int*int %i\n", intValue/secondIntValue);
    
}
