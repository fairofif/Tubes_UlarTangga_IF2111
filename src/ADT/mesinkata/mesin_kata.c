#include "mesin_kata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank() { //untuk input teleport
    while(CC == NEWLINE){
        ADV();
    }
}

void SalinKata(Map *CurrentMap) { //untuk input semua ke array
    int i = 1; //tinggal diubah ke 1 kl mau kepisah2
    while((CC != MARK) && (CC != NEWLINE)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
    assignConfig(CurrentMap);
}

void STARTKATA(Map *CurrentMap) { //untuk nerima input dari semua isi file
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = TRUE;
    }
    else {
        EndKata = FALSE;
        SalinKata(CurrentMap);
    }
}

void ADVKATA(Map *CurrentMap) {
    IgnoreBlank(); 
    if (CC == MARK) {
        EndKata = TRUE;
    }
    else {
        SalinKata(CurrentMap);
    }
}
