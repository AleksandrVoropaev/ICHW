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
    int secondArray[] = {0, 1, 2, 3};
    int thirdArray[4];
    thirdArray[0] = 0;
    thirdArray[1] = 1;
    thirdArray[2] = 2;
    thirdArray[3] = 3;
    
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

void ICPrintNillTerminatedString(const char string[]) {
    for (int iterator = 0; iterator < strlen(string)+1; iterator++ ) {
        printf("%c ", string[iterator]);
    }
    puts("");
}

void ICPrintNillNotTerminatedString(int length, const char string[]) {
    for (int iterator = 0; iterator < length + 1; iterator++) {
        printf("%c ", string[iterator]);
    }
    puts("");
}

void ICPrintNillTerminatedStringLength(const char string[]) {
    printf("%ld\n", strlen(string));
//    const char testString[10] = "Hi";
//    printf("%s-\n", testString);
//    const char testString[10] = "Hello, how are you?";
//    printf("%s\n", testString);
//    const char testString[] = "Hello\0, how are you?";
//    printf("%s\n", testString);
}

void ICArrayLengthFromStringLength(const char string[]) {
    unsigned int length = strlen(string);
    int array[length];
}

void ICPrintArray(unsigned int count, int minValue, int maxValue) {
    (count > 50) ? count = 50 : count;
    
    for (int value = minValue; value < maxValue; value++) {
        if (0 == (value % 3)) {
            continue;
        }
        
        if (50 == value) {
            break;
        }
        
        for (unsigned int iterator = 1; iterator < count + 1; iterator++) {
            printf("%d ", value);
        }
        puts("");
    }
}

void ICPrintMama() {
    printf("Mama");
}

void ICPrintPapa() {
    printf("Papa");
}

void ICPrintNewLine() {
    printf("\n");
}
