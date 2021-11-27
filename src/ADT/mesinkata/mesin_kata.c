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

int KataToInt (Kata K){
    int i = 0;
    int value = 0;

    while (i < K.Length){
        value = value * 10;
        switch (K.TabKata[i]){
            case '0' : 
                value += 0; 
                break;
            case '1' : 
                value += 1; 
                break;
            case '2' : 
                value += 2; 
                break;
            case '3' : 
                value += 3; 
                break;
            case '4' : 
                value += 4; 
                break;
            case '5' : 
                value += 5; 
                break;
            case '6' : 
                value += 6; 
                break;
            case '7' : 
                value += 7; 
                break;
            case '8' : 
                value += 8; 
                break;
            case '9' : 
                value += 9; 
                break;
        };
        i++;
    }
    return value;
}

char KataToChar (Kata K){
    int i = 1;
    while (i <= K.Length){
        return (K.TabKata[i]);
    }
}

void ADVKATA2(){
    IgnoreBlank();
    SalinKata2();
    IgnoreBlank();
}

void SalinKata2() { //untuk input semua ke array
    int i = 1; //tinggal diubah ke 1 kl mau kepisah2
    while((CC != MARK) && (CC != NEWLINE)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}
