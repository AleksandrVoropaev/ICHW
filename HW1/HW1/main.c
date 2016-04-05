//
//  main.c
//  HW1
//
//  Created by Aleksandr Voropaev on 05.04.16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include <stdio.h>

void ICEnter(int number){
    for (int i=0; i < number; i++)
        printf("\n");
}

void ICPrint(){
    printf("Hello, Mama!");
}

/*
 
void ICPrint(){
    printf("Hello, World!\n");
}
 
програма не працює, якщо декілька разів декларувати одну функцію

*/

void ICParents(){
    ICPrint();
    printf(" Hello, Papa!");
}

int main(int argc, const char * argv[]) {
    ICParents();
    ICEnter(3);
    ICParents();
    ICEnter(3);
    return 0;
    ICPrint();
    ICPrint();
    ICPrint();
    ICPrint();
    return 0;
}

//Якщо ICPrint буде після main, то програма не запуститься

/*
 Hello, World!
 Hello, World!
 Hello, World!
 Hello, World!
 Hello, World!
 Program ended with exit code: 0
*/

//Код після return 0 will newer be executed - функція завершує свою дію на цьому рядку