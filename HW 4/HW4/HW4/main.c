//
//  main.c
//  HW4
//
//  Created by Aleksandr Voropaev on 4/7/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>
#include "ICVariablesPrint.h"
#include "ICIncrementDecrement.h"

int main(int argc, const char * argv[]) {
    int integerValue = 1;
    float floatValue = 1.1f;
    char charValue = 'A';
    char stringValue[3] = {'A', 'B', 'C'};
    
    ICVariablesPrint(integerValue, floatValue, charValue, stringValue);
    
    int valueForIncrementation = 1;
    int valueForDecrementation = 1;
    
    printf("%d\n", ICIncrement(valueForIncrementation));
    printf("%d\n", ICDecrement(valueForDecrementation));
    
    return 0;
}
