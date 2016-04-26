//
//  ICBitfieldTest.h
//  StudyPlan1
//
//  Created by Aleksandr Voropaev on 4/26/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef ICBitfieldTest_h
#define ICBitfieldTest_h

#include <stdbool.h>

typedef struct ICStructureWithRandomPlacedElements ICStructureWithRandomPlacedElements;

struct ICStructureWithRandomPlacedElements {
    bool boolValue1;
    float floatValue1;
    bool boolValue2;
    int intValue1;
    bool boolValue3;
    long long longLongValue1;
    bool boolValue4;
    short shortValue1;
    short shortValue2;
    short shortValue3;
    bool boolValue5;
    double doubleValue1;
    bool boolValue6;
    char charValue1;
};

typedef struct ICStructureWithSortedElements ICStructureWithSortedElements;

struct ICStructureWithSortedElements {
    long long longLongValue1;
    double doubleValue1;
    float floatValue1;
    int intValue1;
    short shortValue1;
    short shortValue2;
    short shortValue3;
    char charValue1;
    bool boolValue1;
    bool boolValue2;
    bool boolValue3;
    bool boolValue4;
    bool boolValue5;
    bool boolValue6;
};

void ICPrintOffsetOfStruct();
void ICPrintSizeOfStruct();
void ICPrintOffsetOfOptimizedStruct();
void ICPrintSizeOfOptimizedStruct();

#endif /* ICBitfieldTest_h */
