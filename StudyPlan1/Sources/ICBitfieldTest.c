//
//  ICBitfieldTest.c
//  StudyPlan1
//
//  Created by Aleksandr Voropaev on 4/26/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>
#include <stddef.h>

#include "ICBitfieldTest.h"

#define ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, typeOfVariable, count) \
    printf(#typeOfVariable "Value" #count " is at %lu\n", offsetof(typeOfStruct, typeOfVariable##Value##count))

#define ICGeneratePrintOffsetOfStructElements(typeOfStruct) \
    void ICPrintOffsetOfStruct() {\
        printf("Offsetof: \n");\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, float, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 2);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, int, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 3);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, longLong, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 4);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 2);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 3);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 5);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, double, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 6);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, char, 1);\
        printf("\n");\
    }

#define ICGeneratePrintOffsetOfSortedStructElements(typeOfStruct) \
    void ICPrintOffsetOfSortedStruct() {\
        printf("Offsetof: \n");\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, longLong, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, double, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, float, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, int, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, char, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 2);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 3);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 4);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 5);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, bool, 6);\
        printf("\n");\
    }

#define ICGeneratePrintOffsetStructWithBitfieldElements(typeOfStruct) \
    void ICPrintOffsetOfStructWithBitfield() {\
        printf("Offsetof: \n");\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, longLong, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, double, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, float, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, int, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, short, 1);\
        ICGeneratePrintLineOffsetOfStructElement(typeOfStruct, char, 1);\
        printf("bitfield of six bool values is at %lu\n\n", offsetof(ICStructureWithBitfield, bitfield));\
    }

#define ICGeneratePrintLineSizeOfStructElement(variableName) \
    printf(#variableName " is %lu bytes long\n", sizeof(ICStruct.variableName))

ICGeneratePrintOffsetOfStructElements(ICStructureWithRandomPlacedElements);
void ICPrintSizeOfStruct() {
    ICStructureWithRandomPlacedElements ICStruct;
    printf("Sizeof: \n");
    printf("The Struct with random placed elements is %lu\n", sizeof(ICStruct));
    ICGeneratePrintLineSizeOfStructElement(boolValue1);
    ICGeneratePrintLineSizeOfStructElement(floatValue1);
    ICGeneratePrintLineSizeOfStructElement(boolValue2);
    ICGeneratePrintLineSizeOfStructElement(intValue1);
    ICGeneratePrintLineSizeOfStructElement(boolValue3);
    ICGeneratePrintLineSizeOfStructElement(longLongValue1);
    ICGeneratePrintLineSizeOfStructElement(boolValue4);
    ICGeneratePrintLineSizeOfStructElement(shortValue1);
    ICGeneratePrintLineSizeOfStructElement(shortValue2);
    ICGeneratePrintLineSizeOfStructElement(shortValue3);
    ICGeneratePrintLineSizeOfStructElement(boolValue5);
    ICGeneratePrintLineSizeOfStructElement(doubleValue1);
    ICGeneratePrintLineSizeOfStructElement(boolValue6);
    ICGeneratePrintLineSizeOfStructElement(charValue1);
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.boolValue1) + sizeof(ICStruct.boolValue2)
                                                   + sizeof(ICStruct.boolValue3) + sizeof(ICStruct.boolValue4)
                                                   + sizeof(ICStruct.boolValue5) + sizeof(ICStruct.boolValue6)
                                                   + sizeof(ICStruct.charValue1) + sizeof(ICStruct.doubleValue1)
                                                   + sizeof(ICStruct.floatValue1) + sizeof(ICStruct.intValue1)
                                                   + sizeof(ICStruct.longLongValue1) + sizeof(ICStruct.shortValue1)
                                                   + sizeof(ICStruct.shortValue2) + sizeof(ICStruct.shortValue3)));
}

ICGeneratePrintOffsetOfSortedStructElements(ICStructureWithSortedElements);
void ICPrintSizeOfOptimizedStruct() {
    ICStructureWithSortedElements ICStruct;
    printf("Sizeof: \n");
    printf("The Struct with sorted elements is %lu\n", sizeof(ICStruct));
    ICGeneratePrintLineSizeOfStructElement(longLongValue1);
    ICGeneratePrintLineSizeOfStructElement(doubleValue1);
    ICGeneratePrintLineSizeOfStructElement(floatValue1);
    ICGeneratePrintLineSizeOfStructElement(intValue1);
    ICGeneratePrintLineSizeOfStructElement(shortValue1);
    ICGeneratePrintLineSizeOfStructElement(shortValue2);
    ICGeneratePrintLineSizeOfStructElement(shortValue3);
    ICGeneratePrintLineSizeOfStructElement(charValue1);
    ICGeneratePrintLineSizeOfStructElement(boolValue1);
    ICGeneratePrintLineSizeOfStructElement(boolValue2);
    ICGeneratePrintLineSizeOfStructElement(boolValue3);
    ICGeneratePrintLineSizeOfStructElement(boolValue4);
    ICGeneratePrintLineSizeOfStructElement(boolValue5);
    ICGeneratePrintLineSizeOfStructElement(boolValue6);
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.boolValue1) + sizeof(ICStruct.boolValue2)
                                                   + sizeof(ICStruct.boolValue3) + sizeof(ICStruct.boolValue4)
                                                   + sizeof(ICStruct.boolValue5) + sizeof(ICStruct.boolValue6)
                                                   + sizeof(ICStruct.charValue1) + sizeof(ICStruct.doubleValue1)
                                                   + sizeof(ICStruct.floatValue1) + sizeof(ICStruct.intValue1)
                                                   + sizeof(ICStruct.longLongValue1) + sizeof(ICStruct.shortValue1)
                                                   + sizeof(ICStruct.shortValue2) + sizeof(ICStruct.shortValue3)));
}

ICGeneratePrintOffsetStructWithBitfieldElements(ICStructureWithBitfield);
void ICPrintSizeOfStructWithBitfield() {
    ICStructureWithBitfield ICStruct;
    printf("Sizeof: \n");
    printf("The Struct with sorted elements and bitfield is %lu\n", sizeof(ICStruct));
    ICGeneratePrintLineSizeOfStructElement(longLongValue1);
    ICGeneratePrintLineSizeOfStructElement(doubleValue1);
    ICGeneratePrintLineSizeOfStructElement(floatValue1);
    ICGeneratePrintLineSizeOfStructElement(intValue1);
    ICGeneratePrintLineSizeOfStructElement(shortValue1);
    ICGeneratePrintLineSizeOfStructElement(shortValue2);
    ICGeneratePrintLineSizeOfStructElement(shortValue3);
    ICGeneratePrintLineSizeOfStructElement(charValue1);
    printf("bitfield of six bool values is %lu\n", sizeof(ICStruct.bitfield));
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.bitfield)
                                                   + sizeof(ICStruct.charValue1) + sizeof(ICStruct.doubleValue1)
                                                   + sizeof(ICStruct.floatValue1) + sizeof(ICStruct.intValue1)
                                                   + sizeof(ICStruct.longLongValue1) + sizeof(ICStruct.shortValue1)
                                                   + sizeof(ICStruct.shortValue2) + sizeof(ICStruct.shortValue3)));
}

void ICPrintBitfield() {
    ICStructureWithBitfield ICStruct;
    ICStruct.bitfield = 'A';
    printf("%d %d %d %d %d %d\n", ICStruct.boolValue1, ICStruct.boolValue2, ICStruct.boolValue3, ICStruct.boolValue4, ICStruct.boolValue5, ICStruct.boolValue6);
}
