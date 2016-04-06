//
//  ICPrint.c
//  HW1
//
//  Created by Aleksandr Voropaev on 4/6/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "ICPrint.h"

void ICPrint() {
    printf("Hello, World!\n");
}

void ICPrintParents() {
    ICPrintMama();
    ICPrintPapa();
}

void ICPrintMama() {
    printf("Hello, Mama!\n");
}

void ICPrintPapa() {
    printf("Hello, Papa!\n");
}