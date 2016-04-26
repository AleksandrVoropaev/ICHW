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

void ICPrintOffsetOfStruct() {
    printf("Offsetof: \n");
    printf("boolValue1 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, boolValue1));
    printf("floatValue1 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, floatValue1));
    printf("boolValue2 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, boolValue2));
    printf("intValue1 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, intValue1));
    printf("boolValue3 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, boolValue3));
    printf("longLongValue1 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, longLongValue1));
    printf("boolValue4 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, boolValue4));
    printf("shortValue1 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, shortValue1));
    printf("shortValue2 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, shortValue2));
    printf("shortValue3 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, shortValue3));
    printf("boolValue5 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, boolValue5));
    printf("doubleValue1 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, doubleValue1));
    printf("boolValue6 is at %lu\n", offsetof(ICStructureWithRandomPlacedElements, boolValue6));
    printf("charValue1 is at %lu\n\n", offsetof(ICStructureWithRandomPlacedElements, charValue1));
}

void ICPrintSizeOfStruct() {
    ICStructureWithRandomPlacedElements ICStruct;
    printf("Sizeof: \n");
    printf("The Struct with random placed elements is %lu\n", sizeof(ICStruct));
    printf("boolValue1 is %lu\n", sizeof(ICStruct.boolValue1));
    printf("floatValue1 is %lu\n", sizeof(ICStruct.floatValue1));
    printf("boolValue2 is %lu\n", sizeof(ICStruct.boolValue2));
    printf("intValue1 is %lu\n", sizeof(ICStruct.intValue1));
    printf("boolValue3 is %lu\n", sizeof(ICStruct.boolValue3));
    printf("longLongValue1 is %lu\n", sizeof(ICStruct.longLongValue1));
    printf("boolValue4 is %lu\n", sizeof(ICStruct.boolValue4));
    printf("shortValue1 is %lu\n", sizeof(ICStruct.shortValue1));
    printf("shortValue2 is %lu\n", sizeof(ICStruct.shortValue2));
    printf("shortValue3 is %lu\n", sizeof(ICStruct.shortValue3));
    printf("boolValue5 is %lu\n", sizeof(ICStruct.boolValue5));
    printf("doubleValue1 is %lu\n", sizeof(ICStruct.doubleValue1));
    printf("boolValue6 is %lu\n", sizeof(ICStruct.boolValue6));
    printf("charValue1 is %lu\n", sizeof(ICStruct.charValue1));
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.boolValue1)+sizeof(ICStruct.boolValue2)+sizeof(ICStruct.boolValue3)+sizeof(ICStruct.boolValue4)+sizeof(ICStruct.boolValue5)+sizeof(ICStruct.boolValue6)+sizeof(ICStruct.charValue1)+sizeof(ICStruct.doubleValue1)+sizeof(ICStruct.floatValue1)+sizeof(ICStruct.intValue1)+sizeof(ICStruct.longLongValue1)+sizeof(ICStruct.shortValue1)+sizeof(ICStruct.shortValue2)+sizeof(ICStruct.shortValue3)));
}

void ICPrintOffsetOfOptimizedStruct() {
    printf("Offsetof: \n");
    printf("longLongValue1 is at %lu\n", offsetof(ICStructureWithSortedElements, longLongValue1));
    printf("doubleValue1 is at %lu\n", offsetof(ICStructureWithSortedElements, doubleValue1));
    printf("floatValue1 is at %lu\n", offsetof(ICStructureWithSortedElements, floatValue1));
    printf("intValue1 is at %lu\n", offsetof(ICStructureWithSortedElements, intValue1));
    printf("shortValue1 is at %lu\n", offsetof(ICStructureWithSortedElements, shortValue1));
    printf("shortValue2 is at %lu\n", offsetof(ICStructureWithSortedElements, shortValue2));
    printf("shortValue3 is at %lu\n", offsetof(ICStructureWithSortedElements, shortValue3));
    printf("charValue1 is at %lu\n", offsetof(ICStructureWithSortedElements, charValue1));
    printf("boolValue1 is at %lu\n", offsetof(ICStructureWithSortedElements, boolValue1));
    printf("boolValue2 is at %lu\n", offsetof(ICStructureWithSortedElements, boolValue2));
    printf("boolValue3 is at %lu\n", offsetof(ICStructureWithSortedElements, boolValue3));
    printf("boolValue4 is at %lu\n", offsetof(ICStructureWithSortedElements, boolValue4));
    printf("boolValue5 is at %lu\n", offsetof(ICStructureWithSortedElements, boolValue5));
    printf("boolValue6 is at %lu\n\n", offsetof(ICStructureWithSortedElements, boolValue6));
}

void ICPrintSizeOfOptimizedStruct() {
    ICStructureWithSortedElements ICStruct;
    printf("Sizeof: \n");
    printf("The Struct with sorted elements is %lu\n", sizeof(ICStruct));
    printf("longLongValue1 is %lu\n", sizeof(ICStruct.longLongValue1));
    printf("doubleValue1 is %lu\n", sizeof(ICStruct.doubleValue1));
    printf("floatValue1 is %lu\n", sizeof(ICStruct.floatValue1));
    printf("intValue1 is %lu\n", sizeof(ICStruct.intValue1));
    printf("shortValue1 is %lu\n", sizeof(ICStruct.shortValue1));
    printf("shortValue2 is %lu\n", sizeof(ICStruct.shortValue2));
    printf("shortValue3 is %lu\n", sizeof(ICStruct.shortValue3));
    printf("charValue1 is %lu\n", sizeof(ICStruct.charValue1));
    printf("boolValue1 is %lu\n", sizeof(ICStruct.boolValue1));
    printf("boolValue2 is %lu\n", sizeof(ICStruct.boolValue2));
    printf("boolValue3 is %lu\n", sizeof(ICStruct.boolValue3));
    printf("boolValue4 is %lu\n", sizeof(ICStruct.boolValue4));
    printf("boolValue5 is %lu\n", sizeof(ICStruct.boolValue5));
    printf("boolValue6 is %lu\n", sizeof(ICStruct.boolValue6));
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.boolValue1)+sizeof(ICStruct.boolValue2)+sizeof(ICStruct.boolValue3)+sizeof(ICStruct.boolValue4)+sizeof(ICStruct.boolValue5)+sizeof(ICStruct.boolValue6)+sizeof(ICStruct.charValue1)+sizeof(ICStruct.doubleValue1)+sizeof(ICStruct.floatValue1)+sizeof(ICStruct.intValue1)+sizeof(ICStruct.longLongValue1)+sizeof(ICStruct.shortValue1)+sizeof(ICStruct.shortValue2)+sizeof(ICStruct.shortValue3)));
}

void ICPrintOffsetOfStructWithBitfield() {
    printf("Offsetof: \n");
    printf("longLongValue1 is at %lu\n", offsetof(ICStructureWithBitfield, longLongValue1));
    printf("doubleValue1 is at %lu\n", offsetof(ICStructureWithBitfield, doubleValue1));
    printf("floatValue1 is at %lu\n", offsetof(ICStructureWithBitfield, floatValue1));
    printf("intValue1 is at %lu\n", offsetof(ICStructureWithBitfield, intValue1));
    printf("shortValue1 is at %lu\n", offsetof(ICStructureWithBitfield, shortValue1));
    printf("shortValue2 is at %lu\n", offsetof(ICStructureWithBitfield, shortValue2));
    printf("shortValue3 is at %lu\n", offsetof(ICStructureWithBitfield, shortValue3));
    printf("charValue1 is at %lu\n", offsetof(ICStructureWithBitfield, charValue1));
    printf("boolValue1 is at %lu\n", offsetof(ICStructureWithBitfield, boolValue1));
    printf("boolValue2 is at %lu\n", offsetof(ICStructureWithBitfield, boolValue2));
    printf("boolValue3 is at %lu\n", offsetof(ICStructureWithBitfield, boolValue3));
    printf("boolValue4 is at %lu\n", offsetof(ICStructureWithBitfield, boolValue4));
    printf("boolValue5 is at %lu\n", offsetof(ICStructureWithBitfield, boolValue5));
    printf("boolValue6 is at %lu\n\n", offsetof(ICStructureWithBitfield, boolValue6));
}

void ICPrintSizeOfStructWithBitfield() {
    ICStructureWithBitfield ICStruct;
    printf("Sizeof: \n");
    printf("The Struct with sorted elements and bitfield is %lu\n", sizeof(ICStruct));
    printf("longLongValue1 is %lu\n", sizeof(ICStruct.longLongValue1));
    printf("doubleValue1 is %lu\n", sizeof(ICStruct.doubleValue1));
    printf("floatValue1 is %lu\n", sizeof(ICStruct.floatValue1));
    printf("intValue1 is %lu\n", sizeof(ICStruct.intValue1));
    printf("shortValue1 is %lu\n", sizeof(ICStruct.shortValue1));
    printf("shortValue2 is %lu\n", sizeof(ICStruct.shortValue2));
    printf("shortValue3 is %lu\n", sizeof(ICStruct.shortValue3));
    printf("charValue1 is %lu\n", sizeof(ICStruct.charValue1));
    printf("boolValue1 is %lu\n", sizeof(ICStruct.boolValue1));
    printf("boolValue2 is %lu\n", sizeof(ICStruct.boolValue2));
    printf("boolValue3 is %lu\n", sizeof(ICStruct.boolValue3));
    printf("boolValue4 is %lu\n", sizeof(ICStruct.boolValue4));
    printf("boolValue5 is %lu\n", sizeof(ICStruct.boolValue5));
    printf("boolValue6 is %lu\n", sizeof(ICStruct.boolValue6));
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.boolValue1)+sizeof(ICStruct.boolValue2)+sizeof(ICStruct.boolValue3)+sizeof(ICStruct.boolValue4)+sizeof(ICStruct.boolValue5)+sizeof(ICStruct.boolValue6)+sizeof(ICStruct.charValue1)+sizeof(ICStruct.doubleValue1)+sizeof(ICStruct.floatValue1)+sizeof(ICStruct.intValue1)+sizeof(ICStruct.longLongValue1)+sizeof(ICStruct.shortValue1)+sizeof(ICStruct.shortValue2)+sizeof(ICStruct.shortValue3)));
}
