#include "map.h"

int inputIndicator = 1; //teleport indikator (mengindikasikan input berupa telport)

void inputConfig(Map *CurrentMap) 
{
    char namafile[254];
    char *dummy = "map1.txt";
    boolean valid = FALSE;
    TELEPORT_NEFF(*CurrentMap) = 0;

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
    readConfig(CurrentMap);
}

void readConfig(Map *CurrentMap)
{
    STARTKATA(CurrentMap); 
    while(!EndKata) {
        inputIndicator++;
        ADVKATA(CurrentMap); 
    }
    printf("Input file konfigurasi berhasil..\nSelamat bermain!\n");
}

void assignConfig(Map *CurrentMap)
{
    if(inputIndicator == 2) {
        MAP_LENGTH(*CurrentMap) = CKata.Length;
        for(int i = 1; i <= CKata.Length; i++) {
            MAP_LAYOUT(*CurrentMap)[i] = CKata.TabKata[i];
            MAP_NEFF(*CurrentMap) += 1;
        }
        printf("\n");
        //CEK DULU IF C.LENGTHNYA SAMA KAYA LENGTH
    } else {
        chartoint(CKata.TabKata, CKata.Length, CurrentMap);
    }
}

void printConfig(Map *CurrentMap) 
{
    printf("Panjang map : %d\n", MAP_LENGTH(*CurrentMap));
    printf("Layout map : ");
    for(int i = 0; i < MAP_LENGTH(*CurrentMap); i++) {
        printf("%c", MAP_LAYOUT(*CurrentMap)[i]);
    }
    printf("\n");
    printf("Maksimal dadu : %d\n", MAP_MAXROLL(*CurrentMap));
    printf("Jumlah teleport : %d\n", TELEPORT_COUNT(*CurrentMap));
    printf("List teleport : \n");
    printf("| ");
    for(int i = 0; i < TELEPORT_COUNT(*CurrentMap)*2; i+=2) {
        printf("%d -> %d | ", TELEPORT_LAYOUT(*CurrentMap)[i], TELEPORT_LAYOUT(*CurrentMap)[i+1]);
    }
    printf("\n");

}

void showMap(pPosition (*pP), pUserName (*pU), int playerCount, Map *CurrentMap) 
{
    for(int idxCurrentPlayer = 1; idxCurrentPlayer <= playerCount; idxCurrentPlayer++ ) {
        printf("%s: ", (*pU).uname[idxCurrentPlayer]);
        for(int i = 1; i <= MAP_LENGTH(*CurrentMap); i++) {
            if ((*pP).pos[idxCurrentPlayer] == i) {
                printf("*");
            } else {
                printf("%c", MAP_LAYOUT(*CurrentMap)[i]);
            }
        }
        printf("\n");
    }
}

int rollDice(int max) 
{
    int num = 0;  
    time_t t1;
      
    srand ( (unsigned) time (&t1));

    while (num == 0) {
        num = rand() % (max+1);
    };
    printf( "%d \n", num);
    return num;
}

void movePlayer(int roll, int idxCurrentPlayer, Map *CurrentMap, pPosition (*pP))
{
    int depan = (*pP).pos[idxCurrentPlayer] + roll;
    int belakang = (*pP).pos[idxCurrentPlayer] - roll;

    boolean validMove = FALSE;
    char input[1];
    if (depan <= 20 && belakang >= 1) {
        if (MAP_LAYOUT(*CurrentMap)[depan] == '#') {
            if (MAP_LAYOUT(*CurrentMap)[belakang] == '#') {
                printf("tidak bisa bergerak! karena di depan dan belakang ada pagar!\n");
            } else {
                (*pP).pos[idxCurrentPlayer] = belakang; 
            }
        } else if (MAP_LAYOUT(*CurrentMap)[belakang] == '#') {
            (*pP).pos[idxCurrentPlayer] = depan;
        } else {
            printf("Pilih F untuk Forward dan B untuk Back (F/B) : ");
            while(!validMove) {
                strcpy(input, "");
                scanf("%c", input);
                printf("\n");
                if (input[0] == 'F') {
                    (*pP).pos[idxCurrentPlayer] = depan;
                    validMove = TRUE;
                } else if (input[0] == 'B') {
                    (*pP).pos[idxCurrentPlayer] = belakang;
                    validMove = TRUE;
                } else {
                    printf("Pilih (F/B) : ");
                }
            }
        }
    } else if ((*pP).pos[idxCurrentPlayer] + roll > 20) {
        if (MAP_LAYOUT(*CurrentMap)[belakang] == '#') {
            printf("tidak bisa bergerak! karena ke depan lebih dari 20 dan ke belakang ada pagar\n");
        } else {
            (*pP).pos[idxCurrentPlayer] = belakang;
        }
    } else if ((*pP).pos[idxCurrentPlayer] - roll < 1) {
        if (MAP_LAYOUT(*CurrentMap)[depan] == '#') {
            printf("tidak bisa bergerak! karena ke belakang kurang dari 0 dan ke depan ada pagar!\n");
        } else {
            (*pP).pos[idxCurrentPlayer] = depan;
        }
    } else {
        printf("ERROR! kasus anomali\n");
    }
}

void inspectMap(Map *CurrentMap) 
{
    int n,i;
    int length;
    printf("Masukkan petak: ");
    scanf("%d", &n);

    length = MAP_LENGTH(*CurrentMap);
    for(i = 0; i < length; i+=2) {
        if(TELEPORT_LAYOUT(*CurrentMap)[i] == n) {
            printf("Petak %d memiliki teleporter menuju %d.\n", n, TELEPORT_LAYOUT(*CurrentMap)[i+1]);
        }
    }

    if(MAP_LAYOUT(*CurrentMap)[n] == '.') {
        printf("Petak %d merupakan petak kosong.\n", n);
    } else if(MAP_LAYOUT(*CurrentMap)[n] == '#') {
        printf("Petak %d merupakan petak terlarang.\n", n);
    }
}

void forceMove(int roll, int idxP, Map *CurrentMap, pPosition (*pP), pIsImune (*pI)) {
    int forcedIdx = (*pP).pos[idxP] + roll;
    int length = MAP_LENGTH(*CurrentMap);
    int i;
    char use[3];

    if(MAP_LAYOUT(*CurrentMap)[forcedIdx] != '#') {
        for(i = 0; i < length; i+=2) {
            if(TELEPORT_LAYOUT(*CurrentMap)[i] == forcedIdx) {
                if((*pI).isImun[idxP] == TRUE) {
                    printf("Pakai anti-teleport (Y/N): ");
                    scanf("%s", use);
                    if(strcmp(use, "N")) {
                        (*pP).pos[idxP] = TELEPORT_LAYOUT(*CurrentMap)[i+1];
                    } else if(strcmp(use, "Y")) {
                        (*pI).isImun[idxP] = FALSE;
                    }
                } else {
                    (*pP).pos[idxP] = TELEPORT_LAYOUT(*CurrentMap)[i+1];
                }
            }
        }
        (*pP).pos[idxP] = forcedIdx;
    }
}