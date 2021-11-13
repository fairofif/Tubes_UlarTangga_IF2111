#include "mesin_kata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank() { //untuk input teleport
    while(CC == NEWLINE){
        ADV();
    }
}

void SalinKata() { //untuk input semua ke array
    int i = CKata.Length + 1;
    while((CC != MARK) && (CC != NEWLINE)) {
        CKata.TabKata[i] = CC;
        printf("%c", CKata.TabKata[i]); //PRINTF
        ADV();
        i++;
    }
    printf("\n"); //PRINTF
    CKata.Length = i - 1;
    printf("length kata %d\n", CKata.Length); //PRINTF
}

void STARTKATA() { //untuk nerima input dari semua isi file
    printf("masuk start\n"); //PRINTF
    START(); // 3
    IgnoreBlank();
    printf("%c\n", CC); //PRINTF
    if (CC == MARK) {
        EndKata = TRUE;
    }
    else {
        EndKata = FALSE;
        SalinKata();
    }
}

void ADVKATA() {
    IgnoreBlank(); 
    printf("CC sekarang %c\n", CC); //PRINTF
    if (CC == MARK) {
        printf("masuk ke endkata jd true di advkata\n");
        EndKata = TRUE;
    }
    else {
        SalinKata(); // 6
    }
}
