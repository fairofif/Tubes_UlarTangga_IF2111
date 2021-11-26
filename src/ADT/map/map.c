#include "map.h"
#include "array.h"
#include "array.c"

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
    int IdxTeleIn = 0;
    int IdxTeleOut = 1;
    for(int i = 0; i < TELEPORT_COUNT(CurrentMap); i++) {
        printf("%d %d\n", TELEPORT_LAYOUT(CurrentMap)[IdxTeleIn], TELEPORT_LAYOUT(CurrentMap)[IdxTeleOut]);
        IdxTeleIn = IdxTeleIn + 2;
        IdxTeleOut = IdxTeleOut + 2;
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
    char input[5];
    boolean validMove = FALSE;
    if ((MAP_LAYOUT(CurrentMap)[pP.pos[idxCurrentPlayer] + roll] == '#') && (pP.pos[idxCurrentPlayer] == 1)) {
        printf("tidak bisa bergerak!\n");
    }
    else if ((MAP_LAYOUT(CurrentMap)[pP.pos[idxCurrentPlayer] + roll] == '#') && (MAP_LAYOUT(CurrentMap)[pP.pos[idxCurrentPlayer] - roll] == '#')) {
        printf("tidak bisa bergerak!\n");
    }
    else if (MAP_LAYOUT(CurrentMap)[pP.pos[idxCurrentPlayer] + roll] == '#') {
        printf("Oops ada area terlarang! Kamu hanya dapat bergerak mundur ke belakang! \n");
        pP.pos[idxCurrentPlayer] = pP.pos[idxCurrentPlayer] - roll;
    }
    else if (MAP_LAYOUT(CurrentMap)[pP.pos[idxCurrentPlayer] - roll] == '#') {
        printf("Oops ada area terlarang! Kamu hanya dapat bergerak maju ke depan! \n");
        pP.pos[idxCurrentPlayer] = pP.pos[idxCurrentPlayer] + roll;
    } else {
        printf("pilih F untuk Forward dan B untuk Back (F/B) : ");
        scanf("%s", input);
        while(!validMove) {
            if (strcmp(input, "F") == 0) {
                pP.pos[idxCurrentPlayer] = pP.pos[idxCurrentPlayer] + roll;
                validMove = TRUE;
            } else if (strcmp(input, "B") == 0) {
                pP.pos[idxCurrentPlayer] = pP.pos[idxCurrentPlayer] - roll;
                validMove = TRUE;
            } else {
                printf("pilih (F/B) : ");
                scanf("%c", input);
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

void teleport (int idxCurrentPlayer, Map CurrentMap, int count_tele){
    printf("Anda sekarang berada pada posisi ");
    printf("%d ", pP.pos[idxCurrentPlayer]);
    printf("\n");

    boolean isTeleport = FALSE;
    int IdxTeleIn = 0;
    for(int i = 0; i < TELEPORT_COUNT(CurrentMap); i++){
        if ((pP.pos[idxCurrentPlayer]) == (TELEPORT_LAYOUT(CurrentMap)[IdxTeleIn])){
            isTeleport = TRUE;
        }
        IdxTeleIn += 2;
    }

    if (isTeleport == TRUE){
        printf("Oops, kamu berada pada teleport!\n");
        char s[15];
        if(getImmunityConditionOfPlayer){
            printf("Apakah ingin menggunakan imun (yes/no)? \n");
            scanf("%s",s);
            if (strcmp(s, "no") == 0){
                count_tele++;
            }
        }
        else if (!getImmunityConditionOfPlayer){
            count_tele++;
        }

        if (count_tele == 1){
            int IdxTeleIn = 0;
            int IdxTeleOut = 1;
            for(int i = 0; i < TELEPORT_COUNT(CurrentMap); i++){
                if ((pP.pos[idxCurrentPlayer]) == (TELEPORT_LAYOUT(CurrentMap)[IdxTeleIn])){
                    pP.pos[idxCurrentPlayer] = TELEPORT_LAYOUT(CurrentMap)[IdxTeleOut];
                }
                IdxTeleIn += 2;
                IdxTeleOut += 2;
            }
            printf("Anda sekarang berada pada posisi ");
            printf("%d ", pP.pos[idxCurrentPlayer]);
            printf("\n");
        } 
    }
    else{
        printf("Tidak ada teleport pada petak tersebut\n");
    }
}