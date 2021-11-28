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



// ==================================================////////////////////////////////////////

void STARTKATA2(char *namafile) { //untuk nerima input dari semua isi file
    START2(namafile);
    IgnoreBlank2();

    if (CC == MARK) {
        EndKata = TRUE;
    }
    else {
        EndKata = FALSE;
        SalinKata2();
    }
}

void IgnoreBlank2() { 
    while((CC == NEWLINE)||(CC == BLANK)){
        ADV2();
    }
}

void ADVKATA2(){
    IgnoreBlank2();
    SalinKata2();
    IgnoreBlank2();
}

void SalinKata2() { //untuk input semua ke array
    int i = 1; //tinggal diubah ke 1 kl mau kepisah2
    while((CC != MARK) && (CC != NEWLINE) && (CC != BLANK)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}

int KataToInt (Kata K){
    int value = 0;
    int i = 0;
    while (i <= K.Length)
    {
        value = value * 10;
        switch (K.TabKata[i]){
            case '0' : value += 0; 
                break;
            case '1' : value += 1; 
                break;
            case '2' : value += 2; 
                break;
            case '3' : value += 3; 
                break;
            case '4' : value += 4; 
                break;
            case '5' : value += 5; 
                break;
            case '6' : value += 6; 
                break;
            case '7' : value += 7; 
                break;
            case '8' : value += 8; 
                break;
            case '9' : value += 9; 
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

int KatatoInt(char a[], int len){   
    int tel2;
    int n = 0;
    int valueue = 0;
    for(int i = len; i > 0; i--) {
        if(CKata.TabKata[i] == BLANK) {
            tel2 = valueue;
            valueue = 0;
            n = 0;
        } else {
            int temp = CKata.TabKata[i] - '0';
            valueue = valueue + (temp * pow(10, n));
            n++;
        }
    }
    return 0;
}
