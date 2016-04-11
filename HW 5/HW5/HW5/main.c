//
//  main.c
//  HW5
//
//  Created by Aleksandr Voropaev on 4/7/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#include "ICBoolCheck.h"
#include "ICPrintOperations.h"
#include "ICMathOperations.h"

int main(int argc, const char * argv[]) {
    bool boolValue = true;
    ICCheckTheBool(boolValue);
    
    ICPrintResultOfBoolCompare();
    ICPrintMamaPapaSelection(1, 2);
    ICPrintMamaPapaIfElseSelection(2, 1);
    ICCheckTheDeputy(15, 150000);
    ICPrintTheArray();
    ICPrintNillTerminatedString("String");
    const char string[] = {'S', 't', 'r', 'i', 'n', 'g'};
    ICPrintNillNotTerminatedString( 6, string);
    ICPrintNillTerminatedStringLength("String");
    ICPrintArray(5, 1, 100);
    ICDecisionMamaPapa(44);
    
    return 0;
}
