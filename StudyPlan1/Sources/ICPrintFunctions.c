//
//  ICPrintFunctions.c
//  StudyPlan1
//
//  Created by Aleksandr Voropaev on 4/14/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "ICPrintFunctions.h"

void ICPrintSize() {
    short shortVariable = 0;
    int intVariable = 0;
    double doubleVariable = 0;
    long longVariable = 0;
    float floatVariable = 0;
    char charVariable = 0;
    
    printf("Short is %3lu bytes long \n", sizeof(shortVariable));
    printf("Int is %5lu bytes long \n", sizeof(intVariable));
    printf("Double is %2lu bytes long \n", sizeof(doubleVariable));
    printf("Long is %4lu bytes long \n", sizeof(longVariable));
    printf("Float is %3lu bytes long \n", sizeof(floatVariable));
    printf("Char is %4lu bytes long \n", sizeof(charVariable));
}