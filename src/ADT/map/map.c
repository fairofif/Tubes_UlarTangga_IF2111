#include "map.h"

Map CurrentMap;
int inputIndicator = 1; //teleport indikator (mengindikasikan input berupa telport)

void inputConfig() 
{
    char namafile[254] = "map1.txt";
    char *dummy = "map1.txt";
    boolean valid = FALSE;
    TELEPORT_NEFF(CurrentMap) = 0;

    while(!valid){
        // scanf("%s", namafile);
        if(strcmp(namafile, dummy) == 0) { //ini masih harus ditanya boleh pake strcmp ngga
            fileconfig = &namafile;
            valid = TRUE;
        } else {
            printf("Masukkan file config salah.\n"); 
        }
    }
    readConfig();
}

void readConfig()
{
    STARTKATA(); // 2
    while(!EndKata) {
        inputIndicator++;
        ADVKATA(); // 5
    }
}

void assignConfig()
{
    if(inputIndicator == 2) {
        MAP_LENGTH(CurrentMap) = CKata.Length;
        for(int i = 1; i <= CKata.Length; i++) {
            MAP_LAYOUT(CurrentMap)[i] = CKata.TabKata[i];
            printf("%c", MAP_LAYOUT(CurrentMap)[i]);
        }
        printf("\n");
        //CEK DULU IF C.LENGTHNYA SAMA KAYA LENGTH
    } else {
        int value = 0;
        int n = CKata.Length;
        // printf("input indicator = %d\n", inputIndicator); //PRINTF
        if(inputIndicator > 4) {
            int tel1, tel2;
            n = 0;
            for(int i = CKata.Length; i > 0; i--) {
                if(CKata.TabKata[i] == BLANK) {
                    tel2 = value;
                    value = 0;
                    n = 0;
                } else {
                    int temp = chartoint(CKata.TabKata[i]);
                    value = value + (temp * pow(10, n));
                    n++;
                }
            }
            tel1 = value;
            TELEPORT_LAYOUT(CurrentMap)[TELEPORT_NEFF(CurrentMap)] = tel1;
            TELEPORT_LAYOUT(CurrentMap)[TELEPORT_NEFF(CurrentMap) + 1] = tel2;
            printf("%d %d\n", TELEPORT_LAYOUT(CurrentMap)[TELEPORT_NEFF(CurrentMap)], TELEPORT_LAYOUT(CurrentMap)[TELEPORT_NEFF(CurrentMap) + 1]);   
            TELEPORT_NEFF(CurrentMap) += 2;
        } else {
            for(int i = 1; i <= CKata.Length; i++) {
                int temp = chartoint(CKata.TabKata[i]);
                value = value + (temp * pow(10, n-i));
                if(inputIndicator == 1) {
                    MAP_LENGTH(CurrentMap) = value;
                } else if(inputIndicator == 3) {
                    MAP_MAXROLL(CurrentMap) = value;
                } else if(inputIndicator == 4) {
                    TELEPORT_COUNT(CurrentMap) = value;
                }
            }
        } 
    }
    printf("NEFF %d\n", TELEPORT_NEFF(CurrentMap));
}

// void assignTeleport() {
//     int j = 0;
//     int tel1, tel2;
//     n = 0;
//     for(int i = CKata.Length; i > 0; i--) {
//         if(CKata.TabKata[i] == BLANK) {
//             tel2 = value;
//             value = 0;
//             n = 0;
//         } else {
//             int temp = chartoint(CKata.TabKata[i]);
//             value = value + (temp * pow(10, n));
//             n++;
//         }
//     }
//     tel1 = value;
//     TELEPORT_LAYOUT(CurrentMap)[j] = tel1;
//     TELEPORT_LAYOUT(CurrentMap)[j+1] = tel2;
//     printf("%d %d\n", TELEPORT_LAYOUT(CurrentMap)[j], TELEPORT_LAYOUT(CurrentMap)[j+1]);   
//     j += 2;
// }