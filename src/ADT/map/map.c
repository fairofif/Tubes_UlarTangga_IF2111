#include "map.h"

Map CurrentMap;
int inputIndicator = 1; //teleport indikator (mengindikasikan input berupa telport)

void inputConfig() 
{
    char namafile[254];
    char *dummy = "map1.txt";
    boolean valid = FALSE;
    TELEPORT_NEFF(CurrentMap) = 0;

    while(!valid){
        printf("Masukkan file config txt : ");
        scanf("%s", namafile);
        if(strcmp(namafile, dummy) == 0) { //ini masih harus ditanya boleh pake strcmp ngga
            fileconfig = &namafile;
            valid = TRUE;
        } else {
            printf("File tidak ditemukan. HINT : masukin map1.txt (dummy)\n"); 
        }
    }
    readConfig();
}

void readConfig()
{
    STARTKATA(); 
    while(!EndKata) {
        inputIndicator++;
        ADVKATA(); 
    }
    printf("Input file konfigurasi berhasil..\nSelamat bermain!\n");
}

void assignConfig()
{
    if(inputIndicator == 2) {
        MAP_LENGTH(CurrentMap) = CKata.Length;
        for(int i = 1; i <= CKata.Length; i++) {
            MAP_LAYOUT(CurrentMap)[i] = CKata.TabKata[i];
            MAP_NEFF(CurrentMap) += 1;
        }
        printf("\n");
        //CEK DULU IF C.LENGTHNYA SAMA KAYA LENGTH
    } else {
        chartoint(CKata.TabKata, CKata.Length);
    }
}

void printConfig() 
{
    printf("Panjang map : %d\n", MAP_LENGTH(CurrentMap));
    printf("Layout map : ");
    for(int i = 0; i < MAP_LENGTH(CurrentMap); i++) {
        printf("%c", MAP_LAYOUT(CurrentMap)[i]);
    }
    printf("\n");
    printf("Maksimal dadu : %d\n", MAP_MAXROLL(CurrentMap));
    printf("Jumlah teleport : %d\n", TELEPORT_COUNT(CurrentMap));
    printf("List teleport : \n");
    for(int i = 0; i < TELEPORT_COUNT(CurrentMap); i++) {
        printf("%d %d\n", TELEPORT_LAYOUT(CurrentMap)[i], TELEPORT_LAYOUT(CurrentMap)[i+1]);
    }

}

void showMap() {
    printf("Layout map : ");
    for(int i = 0; i < MAP_LENGTH(CurrentMap); i++) {
        printf("%c", MAP_LAYOUT(CurrentMap)[i]);
    }
    printf("\n");
}