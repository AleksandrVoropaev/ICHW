//
//  ICMacrosTest.c
//  StudyPlan1
//
//  Created by Aleksandr Voropaev on 4/25/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "ICMacrosTest.h"

ICGenerateFunctionWithTypeAndSpecifier(int, i)

void ICRunMacros() {
    ICRunGeneratedFunction(int, 12);
}