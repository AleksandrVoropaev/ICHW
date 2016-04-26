//
//  ICPrintOperations.h
//  HW5
//
//  Created by Aleksandr Voropaev on 4/8/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef ICPrintOperations_h
#define ICPrintOperations_h

typedef enum {
    ICDeputyIsPeculator,
    ICDeputyIsHonest,
    ICDeputyIsAnAngel,
    ICDeputyIsDiedOfStarvation,
} ICDeputyHonest;

void ICPrintBoolComparisonResult();

void ICPrintMamaPapaSelection(int firstValue, int secindValue);
void ICPrintMamaPapaIfElseSelection(int firstValue, int secindValue);

void ICPrintDeputyHonest(ICDeputyHonest deputyHonest);
void ICPrintDeputyHonestWithSalaryAndWeals(float salary, float wealth);

void ICPrintTwoArrays();

void ICPrintStringWithLength(const char string[], unsigned long length);
void ICPrintString(const char string[]);

void ICCreateArrayLengthFromStringLength(const char string[]);
void ICPrintArrayWithoutThirdsValues(unsigned int count, int minValue, int maxValue);

void ICPrintMama();
void ICPrintPapa();
void ICPrintNewLine();

#endif /* ICPrintOperations_h */
