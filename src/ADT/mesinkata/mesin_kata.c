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
        // printf("indeks %d CC", i);
        printf("%c", CKata.TabKata[i]);
        ADV();
        i++;
    }
    printf("\n"); //PRINTF
    CKata.Length = i - 1;
    assignConfig();
}

void STARTKATA() { //untuk nerima input dari semua isi file
    START(); // 3
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
        SalinKata(); // 6
    }
}
