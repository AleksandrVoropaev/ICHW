//
//  ICPrintOperations.c
//  HW5
//
//  Created by Aleksandr Voropaev on 4/8/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>

#include "string.h"
#include "ICPrintOperations.h"
#include "ICMathOperations.h"

void ICPrintResultOfBoolCompare(){
    printf("true && true = %s\n", ICAndOperation(true, true) ? "true" : "false");
    printf("true && false = %s\n", ICAndOperation(true, false) ? "true" : "false");
    printf("false && true = %s\n", ICAndOperation(false, true) ? "true" : "false");
    printf("false && false = %s\n", ICAndOperation(false, false) ? "true" : "false");
    
    printf("true || true = %s\n", ICOrOperation(true, true) ? "true" : "false");
    printf("true || false = %s\n", ICOrOperation(true, false) ? "true" : "false");
    printf("false || true = %s\n", ICOrOperation(false, true) ? "true" : "false");
    printf("false || false = %s\n", ICOrOperation(false, false) ? "true" : "false");
}

void ICPrintMamaPapaSelection(int firstValue, int secindValue) {
    printf("%s\n", (firstValue > secindValue) ? "Mama" : "Papa");
}

void ICPrintMamaPapaIfElseSelection(int firstValue, int secindValue) {
    if (firstValue > secindValue) {
        printf("Mama\n");
    } else {
        printf("Papa\n");
    }
}

void ICPrintHonestyLevel(ICDeputyHonestyLevel honestyLevel) {
    switch (honestyLevel) {
        case 0:
            puts("The deputy is peculator");
            break;
        case 1:
            puts("The deputy is honest");
            break;
        case 2:
            puts("The deputy is an angel");
            break;
        case 3:
            puts("The deputy is died of starvation");
            break;
        default:
            break;
    }
}

void ICCheckTheDeputy(float salary, float wealth) {
    ICDeputyHonestyLevel honestyLevel = (wealth >= salary * 1000) ? 0 : (wealth >= salary * 100) ? 1 : (wealth >= salary * 10) ? 2 : 3;
    ICPrintHonestyLevel(honestyLevel);
}

void ICPrintTheArray() {
//    int *firstArray = {0, 1, 2, 3};
    int secondArray[] = {0, 1, 2, 3};
    int thirdArray[4];
    thirdArray[0] = 0;
    thirdArray[1] = 1;
    thirdArray[2] = 2;
    thirdArray[3] = 3;
    
//    for (int iterator = 0; iterator < 3; iterator++) {
//        printf("%d ", firstArray[iterator]);
//    }
    puts("");
    
    int iterator = 0;
    while (iterator < 4) {
        printf("%d ", secondArray[iterator]);
        iterator++;
    }
    puts("");
    
    iterator = 0;
    do {
        printf("%d ", thirdArray[iterator]);
        iterator++;
    } while (iterator < 4);
    puts("");
}

void ICPrintString() {
    const char nilTerminated[] = "String";
    const char nilNotTerminated[] = {'S', 't', 'r', 'i', 'n', 'g'};
    
    for (int iterator = 0; iterator < strlen(nilTerminated)+1; iterator++ ) {
        printf("%c", nilTerminated[iterator]);
    }
    puts("");
    for (int iterator = 0; iterator < strlen(nilNotTerminated)+1; iterator++) {
        printf("%c", nilNotTerminated[iterator]);
    }
    puts("");
}
