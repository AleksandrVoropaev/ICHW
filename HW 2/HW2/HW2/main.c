//
//  main.c
//  HW2
//
//  Created by Aleksandr Voropaev on 4/7/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    short shortNumber = 1;
    int intNumber = 2;
    long longNumber = 3l;
    long long longLongNumber = 4ll;
    unsigned short unsignedShortNumber = 1;
    unsigned int unsignedIntNumber = 2;
    unsigned long unsignedLongNumber = 3lu;
    unsigned long long unsignedLongLongNumber = 4llu;
    char charNumber = 65;
    char charChar = 'A';
    
    printf("short %d\n", shortNumber);
    printf("int %i\n", intNumber);
    printf("long %ld\n", longNumber);
    printf("long long %lld\n", longLongNumber);
    printf("unsigned short %hu\n", unsignedShortNumber);
    printf("unsigned int %i\n", unsignedIntNumber);
    printf("unsigned long %lu\n", unsignedLongNumber);
    printf("unsigned long long %llu\n", unsignedLongLongNumber);
    printf("char as number %d\n", charNumber);
    printf("char %c\n", charChar);
    
    int intValue = 3;
    double doubleResult = intValue * intValue / 4 % 7 + 4.0 * intValue - 1.5 + 'A';
    
    printf("%f\n", doubleResult);
    
    return 0;
}
