//
//  ICBitfieldTest.c
//  StudyPlan1
//
//  Created by Aleksandr Voropaev on 4/26/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "ICBitfieldTest.h"

#define ICPrintStructValueOffset(structType, variable, index) \
    printf(#variable "Value" #index " is at %lu\n", offsetof(structType, variable##Value##index))

#define ICPrintStructValueSizeof(variable) \
    printf(#variable " is %lu bytes long\n", sizeof(ICStruct.variable))

void ICPrintRandomStructOffset() {
#define ICPrintRandomStructValueOffset(variable, index) \
    ICPrintStructValueOffset(ICStructureWithRandomPlacedElements, variable, index)

    printf("Ofsetof ICStructureWithRandomPlacedElements\n");
    ICPrintRandomStructValueOffset(b0ol, 1);
    ICPrintRandomStructValueOffset(float, 1);
    ICPrintRandomStructValueOffset(b0ol, 2);
    ICPrintRandomStructValueOffset(int, 1);
    ICPrintRandomStructValueOffset(b0ol, 3);
    ICPrintRandomStructValueOffset(longLong, 1);
    ICPrintRandomStructValueOffset(b0ol, 4);
    ICPrintRandomStructValueOffset(short, 1);
    ICPrintRandomStructValueOffset(short, 2);
    ICPrintRandomStructValueOffset(short, 3);
    ICPrintRandomStructValueOffset(b0ol, 5);
    ICPrintRandomStructValueOffset(double, 1);
    ICPrintRandomStructValueOffset(b0ol, 6);
    ICPrintRandomStructValueOffset(char, 1);
    
#undef ICPrintRandomStructValueOffset
}

void ICPrintRandomStructSizeof() {
#define ICPrintRandomStructValueSizeof(variable) \
    ICPrintStructValueSizeof(variable)
    
    ICStructureWithRandomPlacedElements ICStruct;
    printf("Struct with random placed elements is %lu bytes long\n", sizeof(ICStruct));
    ICPrintRandomStructValueSizeof(b0olValue1);
    ICPrintRandomStructValueSizeof(floatValue1);
    ICPrintRandomStructValueSizeof(b0olValue2);
    ICPrintRandomStructValueSizeof(intValue1);
    ICPrintRandomStructValueSizeof(b0olValue3);
    ICPrintRandomStructValueSizeof(longLongValue1);
    ICPrintRandomStructValueSizeof(b0olValue4);
    ICPrintRandomStructValueSizeof(shortValue1);
    ICPrintRandomStructValueSizeof(shortValue2);
    ICPrintRandomStructValueSizeof(shortValue3);
    ICPrintRandomStructValueSizeof(b0olValue5);
    ICPrintRandomStructValueSizeof(doubleValue1);
    ICPrintRandomStructValueSizeof(b0olValue6);
    ICPrintRandomStructValueSizeof(charValue1);
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.b0olValue1) + sizeof(ICStruct.b0olValue2)
                                                   + sizeof(ICStruct.b0olValue3) + sizeof(ICStruct.b0olValue4)
                                                   + sizeof(ICStruct.b0olValue5) + sizeof(ICStruct.b0olValue6)
                                                   + sizeof(ICStruct.longLongValue1) + sizeof(ICStruct.doubleValue1)
                                                   + sizeof(ICStruct.floatValue1) + sizeof(ICStruct.intValue1)
                                                   + sizeof(ICStruct.shortValue1) + sizeof(ICStruct.shortValue2)
                                                   + sizeof(ICStruct.shortValue3) + sizeof(ICStruct.charValue1)));

#undef ICPrintRandomStructValueSizeof
}

void ICPrintSortedStructOffset() {
#define ICPrintSortedStructValueOffset(variable, index) \
    ICPrintStructValueOffset(ICStructureWithSortedElements, variable, index)
    
    printf("Ofsetof ICStructureWithSortedElements\n");
    ICPrintSortedStructValueOffset(longLong, 1);
    ICPrintSortedStructValueOffset(double, 1);
    ICPrintSortedStructValueOffset(float, 1);
    ICPrintSortedStructValueOffset(int, 1);
    ICPrintSortedStructValueOffset(short, 1);
    ICPrintSortedStructValueOffset(short, 2);
    ICPrintSortedStructValueOffset(short, 3);
    ICPrintSortedStructValueOffset(char, 1);
    ICPrintSortedStructValueOffset(b0ol, 1);
    ICPrintSortedStructValueOffset(b0ol, 2);
    ICPrintSortedStructValueOffset(b0ol, 3);
    ICPrintSortedStructValueOffset(b0ol, 4);
    ICPrintSortedStructValueOffset(b0ol, 5);
    ICPrintSortedStructValueOffset(b0ol, 6);
    
#undef ICPrintSortedStructValueOffset
}

void ICPrintSortedStructSizeof() {
#define ICPrintSortedStructValueSizeof(variable) \
ICPrintStructValueSizeof(variable)
    
    ICStructureWithSortedElements ICStruct;
    printf("Struct with random placed elements is %lu bytes long\n", sizeof(ICStruct));
    ICPrintSortedStructValueSizeof(longLongValue1);
    ICPrintSortedStructValueSizeof(doubleValue1);
    ICPrintSortedStructValueSizeof(floatValue1);
    ICPrintSortedStructValueSizeof(intValue1);
    ICPrintSortedStructValueSizeof(shortValue1);
    ICPrintSortedStructValueSizeof(shortValue2);
    ICPrintSortedStructValueSizeof(shortValue3);
    ICPrintSortedStructValueSizeof(charValue1);
    ICPrintSortedStructValueSizeof(b0olValue1);
    ICPrintSortedStructValueSizeof(b0olValue2);
    ICPrintSortedStructValueSizeof(b0olValue3);
    ICPrintSortedStructValueSizeof(b0olValue4);
    ICPrintSortedStructValueSizeof(b0olValue5);
    ICPrintSortedStructValueSizeof(b0olValue6);
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.b0olValue1) + sizeof(ICStruct.b0olValue2)
                                                   + sizeof(ICStruct.b0olValue3) + sizeof(ICStruct.b0olValue4)
                                                   + sizeof(ICStruct.b0olValue5) + sizeof(ICStruct.b0olValue6)
                                                   + sizeof(ICStruct.longLongValue1) + sizeof(ICStruct.doubleValue1)
                                                   + sizeof(ICStruct.floatValue1) + sizeof(ICStruct.intValue1)
                                                   + sizeof(ICStruct.shortValue1) + sizeof(ICStruct.shortValue2)
                                                   + sizeof(ICStruct.shortValue3) + sizeof(ICStruct.charValue1)));
    
#undef ICPrintSortedStructValueSizeof
}

void ICPrintStructWithBitfieldOffset() {
#define ICPrintStructWithBitfieldValueOffset(variable, index) \
    ICPrintStructValueOffset(ICStructureWithBitfield, variable, index)
    
    printf("Ofsetof ICStructureWithBitfield\n");
    ICPrintStructWithBitfieldValueOffset(longLong, 1);
    ICPrintStructWithBitfieldValueOffset(double, 1);
    ICPrintStructWithBitfieldValueOffset(float, 1);
    ICPrintStructWithBitfieldValueOffset(int, 1);
    ICPrintStructWithBitfieldValueOffset(short, 1);
    ICPrintStructWithBitfieldValueOffset(short, 2);
    ICPrintStructWithBitfieldValueOffset(short, 3);
    ICPrintStructWithBitfieldValueOffset(char, 1);
    printf("Bitfield is at %lu\n", offsetof(ICStructureWithBitfield, bitfield));
   
#undef ICPrintStructWithBitfieldValueOffset
}

void ICPrintStructWithBitfieldSizeof() {
#define ICPrintStructWithBitfieldValueSizeof(variable) \
ICPrintStructValueSizeof(variable)
    
    ICStructureWithBitfield ICStruct;
    printf("Struct with random placed elements is %lu bytes long\n", sizeof(ICStruct));
    ICPrintStructWithBitfieldValueSizeof(longLongValue1);
    ICPrintStructWithBitfieldValueSizeof(doubleValue1);
    ICPrintStructWithBitfieldValueSizeof(floatValue1);
    ICPrintStructWithBitfieldValueSizeof(intValue1);
    ICPrintStructWithBitfieldValueSizeof(shortValue1);
    ICPrintStructWithBitfieldValueSizeof(shortValue2);
    ICPrintStructWithBitfieldValueSizeof(shortValue3);
    ICPrintStructWithBitfieldValueSizeof(charValue1);
    ICPrintStructWithBitfieldValueSizeof(bitfield);
    printf("Sum of sizes of elements is %lu\n\n", (sizeof(ICStruct.bitfield)
                                                   + sizeof(ICStruct.longLongValue1) + sizeof(ICStruct.doubleValue1)
                                                   + sizeof(ICStruct.floatValue1) + sizeof(ICStruct.intValue1)
                                                   + sizeof(ICStruct.shortValue1) + sizeof(ICStruct.shortValue2)
                                                   + sizeof(ICStruct.shortValue3) + sizeof(ICStruct.charValue1)));
    
#undef ICPrintStructWithBitfieldValueSizeof
}

void ICPrintBitfield() {
    ICStructureWithBitfield ICStruct;
    ICStruct.bitfield = 5;
    printf("%d %d %d %d %d %d\n", ICStruct.b0olValue6, ICStruct.b0olValue5, ICStruct.b0olValue4, ICStruct.b0olValue3, ICStruct.b0olValue2, ICStruct.b0olValue1);
}

static const uint8_t kICByteLength = 8;
const char *kICBigEndian = "big-endian";
const char *kICLittleEndian = "little-endian";


void ICByteOutput(uint8_t byte) {
    uint8_t byteLength = kICByteLength;
    printf(" - ");
    for (uint8_t bitShiftCount = 0; bitShiftCount < byteLength; bitShiftCount++) {
        uint8_t bitValue = byte >> (byteLength - bitShiftCount - 1);
        printf("%d", bitValue & 1);
        if (bitShiftCount != 7) {
            printf(" ");
        }
    }
    
    printf(" - ");
}

void ICVariableBitOutput(void *address, size_t size) {
    ICVariableBitOutputWithEndianess(address, size, ICGetEndianess());
}


void ICVariableBitOutputWithEndianess(void *address, size_t size, char *endianess) {
    uint8_t *byte = (uint8_t *)address;
    printf(" {");
    bool isLittle = (endianess == kICLittleEndian);
    for (size_t iterator = 0; iterator < size; iterator++) {
        size_t index = isLittle ? iterator : size - iterator - 1;
        ICByteOutput(byte[index]);
    }
    
    printf("}\n\n");
}

char *ICGetEndianess() {
    uint16_t bigLittleEndianTest = 1;
    char *result = ((uint8_t *)&bigLittleEndianTest)[0] == 0 ? kICBigEndian : kICLittleEndian;
    
    return result;
}
