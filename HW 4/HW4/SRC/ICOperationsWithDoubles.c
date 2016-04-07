//
//  ICOperationsWithDoubles.c
//  HW4
//
//  Created by Aleksandr Voropaev on 4/7/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "ICOperationsWithDoubles.h"

void ICDivideEquation() {
    float doubleResult = 3.0;
    doubleResult = doubleResult * doubleResult / 4 /*% 7*/ + 4.0 * doubleResult - 1.5 + 'A';
    printf("%f\n", doubleResult);
    
    doubleResult = 3.0;
    double temp = doubleResult;
    temp *= temp;
    temp /= 4;
    //temp %= 7;
    doubleResult *= 4.0;
    doubleResult -= 1.5;
    doubleResult += 'A';
    doubleResult += temp;
    printf("%f\n", doubleResult);

}