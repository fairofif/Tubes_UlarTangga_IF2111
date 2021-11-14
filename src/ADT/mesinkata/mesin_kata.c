#include "../map/map.h"
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
    int i = 1; //tinggal diubah ke 1 kl mau kepisah2
    while((CC != MARK) && (CC != NEWLINE)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
    assignConfig();
}

void STARTKATA() { //untuk nerima input dari semua isi file
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
