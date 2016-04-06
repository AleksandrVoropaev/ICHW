//
//  main.c
//  HW1
//
//  Created by Aleksandr Voropaev on 05.04.16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>

#include "ICPrint.h"
#include "ICPrint.h"
#include "ICPrint.h"
#include "ICDigitsPrint.h"
#include "ICDigitsPrint.h"

int main(int argc, const char * argv[]) {
    ICPrint();
    ICPrintPapa();
    ICPrintMama();
    ICPrintParents();
    
    ICIncDigitsPrint();
    ICDescDigitsPrint();
    
    return 0;
}
