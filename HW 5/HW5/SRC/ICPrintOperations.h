//
//  ICPrintOperations.h
//  HW5
//
//  Created by Aleksandr Voropaev on 4/8/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef ICPrintOperations_h
#define ICPrintOperations_h

void ICPrintResultOfBoolCompare();
void ICPrintMamaPapaSelection(int firstValue, int secindValue);
void ICPrintMamaPapaIfElseSelection(int firstValue, int secindValue);

typedef enum {
    peculator,
    honest,
    angel,
    diedOfStarvation,
} ICDeputyHonestyLevel;

void ICPrintHonestyLevel(ICDeputyHonestyLevel honestyLevel);
void ICCheckTheDeputy(float salary, float wealth);

void ICPrintTheArray();

#endif /* ICPrintOperations_h */
