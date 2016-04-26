//
//  ICRunAplication.c
//  HW5
//
//  Created by Aleksandr Voropaev on 4/11/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdbool.h>

#include "ICRunAplication.h"
#include "ICBoolCheck.h"
#include "ICPrintOperations.h"
#include "ICMathOperations.h"

void ICRunApplication() {
    ICPrintBoolValue(true);

    ICPrintBoolComparisonResult();
    
    ICPrintMamaPapaSelection(1, 2);
    ICPrintMamaPapaIfElseSelection(2, 1);
    
    ICPrintDeputyHonestWithSalaryAndWeals(15, 150000);
    
    ICPrintTwoArrays();
    
    const char string[] = {'S', 't', 'r', 'i', 'n', 'g'};
    ICPrintStringWithLength(string, 6);
    ICPrintString("String");
    
    ICPrintArrayWithoutThirdsValues(5, 1, 100);
    
    printf("%d\n", ICMamaPapaPrintTypeWithVariable(15));
}
