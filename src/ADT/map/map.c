#include "map.h"

Map CurrentMap;
pPosition pP;

int inputIndicator = 1; //teleport indikator (mengindikasikan input berupa telport)

void inputConfig() 
{
    printf("masuk config");
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

void showMap(char array[],int pPos) 
{
    printf("%c%c%c%c : ", array[0], array[1], array [2], array[3]);
    for(int i = 1; i <= MAP_LENGTH(CurrentMap); i++) {
        if (pPos == i) {
            printf("*");
        } else {
            printf("%c", MAP_LAYOUT(CurrentMap)[i]);
        }
    }
    printf("\n");
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

void movePlayer(int roll, int idxCurrentPlayer, Map CurrentMap)
{
    boolean validMove = FALSE;
    char input[1];
    if (MAP_LAYOUT(CurrentMap)[pP.pos[idxCurrentPlayer] + roll] == '#') {
        if (MAP_LAYOUT(CurrentMap)[pP.pos[idxCurrentPlayer] - roll] == '#') {
            printf("tidak bisa bergerak!\n");
        }
        pP.pos[idxCurrentPlayer] = pP.pos[idxCurrentPlayer] - roll;
    } else if (MAP_LAYOUT(CurrentMap)[pP.pos[idxCurrentPlayer] - roll] == '#') {
        pP.pos[idxCurrentPlayer] = pP.pos[idxCurrentPlayer] + roll;
    } else {
        printf("pilih F untuk Forward dan B untuk Back (F/B) : ");
        while(!validMove) {
            strcpy(input, "");
            scanf("%c", input);
            printf("\n");
            if (input[0] == 'F') {
                pP.pos[idxCurrentPlayer] = pP.pos[idxCurrentPlayer] + roll;
                validMove = TRUE;
            } else if (input[0] == 'B') {
                pP.pos[idxCurrentPlayer] = pP.pos[idxCurrentPlayer] - roll;
                validMove = TRUE;
            } else {
                printf("pilih (F/B) : ");
            }
        }
    }
}

void inspectMap(Map CurrentMap) 
{
    int n,i;
    int length;
    printf("Masukkan petak: ");
    scanf("%d", &n);

    length = MAP_LENGTH(CurrentMap);
    for(i = 0; i < length; i+=2) {
        if(TELEPORT_LAYOUT(CurrentMap)[i] == n) {
            printf("Petak %d memiliki teleporter menuju %d.\n", n, TELEPORT_LAYOUT(CurrentMap)[i+1]);
        }
    }

    if(MAP_LAYOUT(CurrentMap)[n] == '.') {
        printf("Petak %d merupakan petak kosong.\n", n);
    } else if(MAP_LAYOUT(CurrentMap)[n] == '#') {
        printf("Petak %d merupakan petak terlarang.\n", n);
    }
}

void forceMove(int roll, int idxCurrentPlayer, Map CurrentMap) {
    int forcedIdx = pP.pos[idxCurrentPlayer] + roll;
    if(MAP_LAYOUT(CurrentMap)[forcedIdx] != '#') {
        pP.pos[idxCurrentPlayer] = forcedIdx;
    }
}