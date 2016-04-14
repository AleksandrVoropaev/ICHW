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
#include "ICBoolCheck.h"

void ICPrintBoolComparisonResult(){
    printf("true && true = ");
    ICPrintBoolValue(ICAndOperation(true, true));
    printf("true && false = ");
    ICPrintBoolValue(ICAndOperation(true, false));
    printf("false && true = ");
    ICPrintBoolValue(ICAndOperation(false, true));
    printf("false && false = ");
    ICPrintBoolValue(ICAndOperation(false, false));
    
    printf("true || true = ");
    ICPrintBoolValue(ICOrOperation(true, true));
    printf("true || false = ");
    ICPrintBoolValue(ICOrOperation(true, false));
    printf("false || true = ");
    ICPrintBoolValue(ICOrOperation(false, true));
    printf("false || false = ");
    ICPrintBoolValue(ICOrOperation(false, false));
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

void ICPrintDeputyHonest(ICDeputyHonest value) {
    printf("The deputy is ");
    switch (value) {
        case 0:
            puts("peculator");
            break;
        case 1:
            puts("honest");
            break;
        case 2:
            puts("an angel");
            break;
        case 3:
            puts("died of starvation");
            break;
        default:
            break;
    }
}

void ICPrintDeputyHonestWithSalaryAndWeals(float salary, float wealth) {
    ICDeputyHonest deputyHonest = (wealth >= salary * 1000) ? 0
                                : (wealth >= salary * 100) ? 1
                                : (wealth >= salary * 10) ? 2
                                : 3;
    ICPrintDeputyHonest(deputyHonest);
}

void ICPrintTwoArrays() {
    int firstArray[] = {3, 2, 1, 0};
    
    int secondArray[4];
    secondArray[0] = 0;
    secondArray[1] = 1;
    secondArray[2] = 2;
    secondArray[3] = 3;
    
    int iterator = 0;
    while (iterator < 4) {
        printf("%d ", firstArray[iterator]);
        iterator++;
    }
    
    puts("");
    
    iterator = 0;
    do {
        printf("%d ", secondArray[iterator]);
        iterator++;
    } while (iterator < 4);
    
    puts("");
}

void ICPrintStringWithLength(const char string[], unsigned long length) {
    for (unsigned long iterator = 0; iterator < length + 1; iterator++) {
        printf("%c ", string[iterator]);
    }
    
    puts("");
}

void ICPrintString(const char string[]) {
    ICPrintStringWithLength(string, strlen(string));
}

void ICCreateArrayLengthFromStringLength(const char string[]) {
    unsigned long length = strlen(string);
    unsigned long array[length];
}

void ICPrintArrayWithoutThirdsValues(unsigned int count, int minValue, int maxValue) {
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
