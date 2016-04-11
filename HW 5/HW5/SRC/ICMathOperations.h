//
//  ICMathOperations.h
//  HW5
//
//  Created by Aleksandr Voropaev on 4/8/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef ICMathOperations_h
#define ICMathOperations_h

#include <stdbool.h>

typedef enum {
    ICPrintedMama,
    ICPrintedPapa,
    ICPrintedMamaPapa,
    ICNothigPrinted,
} ICVarietyOfOptionsToBePrintedAmongMamaPapaOrNewLine;

bool ICAndOperation(bool firstValue, bool secondValue);
bool ICOrOperation(bool firstValue, bool secondValue);
ICVarietyOfOptionsToBePrintedAmongMamaPapaOrNewLine ICPrintMamaPapaOptionAccordingToGivenVariable(int value);

#endif /* ICMathOperations_h */
