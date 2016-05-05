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
    bool b0olValue1;
    float floatValue1;
    bool b0olValue2;
    int intValue1;
    bool b0olValue3;
    long long longLongValue1;
    bool b0olValue4;
    short shortValue1;
    short shortValue2;
    short shortValue3;
    bool b0olValue5;
    double doubleValue1;
    bool b0olValue6;
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
    bool b0olValue1;
    bool b0olValue2;
    bool b0olValue3;
    bool b0olValue4;
    bool b0olValue5;
    bool b0olValue6;
};

typedef struct ICStructureWithBitfield ICStructureWithBitfield;
struct ICStructureWithBitfield {
    long long longLongValue1;
    double doubleValue1;
    float floatValue1;
    int intValue1;
    short shortValue1;
    short shortValue2;
    short shortValue3;
    char charValue1;
    union {
        struct {
            bool b0olValue1 :1;
            bool b0olValue2 :1;
            bool b0olValue3 :1;
            bool b0olValue4 :1;
            bool b0olValue5 :1;
            bool b0olValue6 :1;
        };
        char bitfield;
    };
};

void ICPrintRandomStructOffset();
void ICPrintRandomStructSizeof();
void ICPrintSortedStructOffset();
void ICPrintSortedStructSizeof();

extern const char *const kICBigEndian;
extern const char *const kICLittleEndian;


void ICPrintStructWithBitfieldOffset();
void ICPrintStructWithBitfieldSizeof();

void ICPrintBitfield();
void ICByteOutput(uint8_t byte);
void ICVariableBitOutput(void *firstByteAdress, size_t variableTypeSize);
void ICVariableBitOutputWithEndianess(void *firstByteAdress, size_t variableTypeSize, const char *const endianess);

const char *const ICGetEndianess();

#endif /* ICBitfieldTest_h */
