#include "mesin_kata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank() {
    while(CC == BLANK){
        ADV();
    }
}

void SalinKata() {
    int i;
    i = 1;
    while((CC != MARK) && (CC != BLANK)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}

void STARTKATA() {
    START();
    IgnoreBlank();
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
    if (CC == MARK) {
        EndKata = TRUE;
    }
    else {
        SalinKata();
    }
}
