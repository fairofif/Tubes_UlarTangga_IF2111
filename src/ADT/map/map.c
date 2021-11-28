#include "map.h"

int inputIndicator = 1; //teleport indikator (mengindikasikan input berupa telport)

void inputConfig(Map *CurrentMap) 
{
    char namafile[254];
    boolean valid = FALSE;
    TELEPORT_NEFF(*CurrentMap) = 0;

    while(!valid){
        printf("\nKONFIGURASI MAP YANG TERSEDIA : \n\n1.RAT-RACE(ratrace.txt) -> Difficulty 9/10, Fun 3/10\n2.FLOOR-ISLAVA(lavafloor.txt) -> Difficulty 6/10, Fun 7/10\n\n"); 
        printf("Masukkan file config txt : ");
        scanf("%s", namafile);
        if((strcmp(namafile, "ratrace.txt") == 0) || (strcmp(namafile, "lavafloor.txt") == 0)) {
            fileconfig = &namafile;
            valid = TRUE;
        } else {
            printf("\nMasukkan salah!");
            printf("\nKONFIGURASI MAP YANG TERSEDIA : \n\n1.RAT-RACE(ratrace.txt) -> Difficulty 9/10, Fun 3/10\n2.FLOOR-ISLAVA(lavafloor.txt) -> Difficulty 6/10, Fun 7/10\n\n"); 
        }
    }
    readConfig(CurrentMap);
}

void loadConfig(Map *CurrentMap, char configmap[]){
    TELEPORT_NEFF(*CurrentMap) = 0;
    fileconfig = configmap;
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
    for(int i = 1; i <= MAP_LENGTH(*CurrentMap); i++) {
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

    while (num == 0) {
        num = rand() % (max+1);
    };
    printf("\nHasil roll adalah %d \n", num);
    return num;
}

void movePlayer(int roll, int idxCurrentPlayer, Map *CurrentMap, pPosition (*pP))
{
    int depan = (*pP).pos[idxCurrentPlayer] + roll;
    int belakang = (*pP).pos[idxCurrentPlayer] - roll;
    int ujungmap = MAP_LENGTH(*CurrentMap);
    int awalmap = 1;

    boolean validMove = FALSE;
    char input[1];
    if (depan <= ujungmap && belakang >= awalmap) {
        if (MAP_LAYOUT(*CurrentMap)[depan] == '#') {
            if (MAP_LAYOUT(*CurrentMap)[belakang] == '#') {
                printf("tidak bisa bergerak! karena di depan dan belakang ada pagar!\n");
            } else {
                (*pP).pos[idxCurrentPlayer] = belakang; 
                printf("anda berhasil mundur sebanyak %d petak ke petak %d\n", roll, belakang);
            }
        } else if (MAP_LAYOUT(*CurrentMap)[belakang] == '#') {
            (*pP).pos[idxCurrentPlayer] = depan;
            printf("anda berhasil maju sebanyak %d petak ke petak %d\n", roll, depan);
        } else {
            printf("Pilih F untuk Forward dan B untuk Back (F/B) : ");
            while(!validMove) {
                strcpy(input, "");
                scanf("%c", input);
                printf("\n");
                if (input[0] == 'F') {
                    (*pP).pos[idxCurrentPlayer] = depan;
                    printf("anda berhasil maju sebanyak %d petak ke petak %d\n", roll, depan);
                    validMove = TRUE;
                } else if (input[0] == 'B') {
                    (*pP).pos[idxCurrentPlayer] = belakang;
                    printf("anda berhasil mundur sebanyak %d petak ke petak %d\n", roll, belakang);
                    validMove = TRUE;
                } else {
                    printf("Pilih (F/B) : ");
                }
            }
        }
    } else if (depan > ujungmap && belakang < awalmap) {
        printf("tidak bisa bergerak! karena hasil roll melebihi layout map!\n");
    } else if ((*pP).pos[idxCurrentPlayer] + roll > ujungmap) {
        if (MAP_LAYOUT(*CurrentMap)[belakang] == '#') {
            printf("tidak bisa bergerak! karena ke depan lebih dari 20 dan ke belakang ada pagar\n");
        } else {
            (*pP).pos[idxCurrentPlayer] = belakang;
            printf("anda berhasil mundur sebanyak %d petak ke petak %d\n", roll, belakang);
        }
    } else if ((*pP).pos[idxCurrentPlayer] - roll < awalmap) {
        if (MAP_LAYOUT(*CurrentMap)[depan] == '#') {
            printf("tidak bisa bergerak! karena ke belakang kurang dari 0 dan ke depan ada pagar!\n");
        } else {
            (*pP).pos[idxCurrentPlayer] = depan;
            printf("anda berhasil maju sebanyak %d petak ke petak %d\n", roll, depan);
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

void forceMove(int roll, int idxP, Map *CurrentMap, pPosition *pP, pIsImune *pI) {
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
                    if(strcmp(use, "N") == 0) {
                        (*pP).pos[idxP] = TELEPORT_LAYOUT(*CurrentMap)[i+1];
                        printf("Anda tidak memanfaatkan Buff antiteleport, otomatis dipindahkan.\n");
                    } else if(strcmp(use, "Y") == 0) {
                        (*pI).isImun[idxP] = FALSE;
                        printf("Kamu memakai anti-teleport sehingga posisi Anda tidak berubah\n");
                    }
                } else {
                    (*pP).pos[idxP] = TELEPORT_LAYOUT(*CurrentMap)[i+1];
                }
            }
        }
        (*pP).pos[idxP] = forcedIdx;
    }
    else {
        printf("Titik tersebut merupakan #. Tidak Jadi dipindahkan paksa.\n");
    }
}

void teleport (int idxCurrentPlayer, Map *CurrentMap, pPosition *pP, pIsImune *pI, pIsTeleported *pT){
    printf("Anda sekarang berada pada posisi ");
    printf("%d ", (*pP).pos[idxCurrentPlayer]);
    printf("\n");

    boolean isTeleport = FALSE;
    int IdxTeleIn = 0;
    for(int i = 0; i < TELEPORT_COUNT(*CurrentMap); i++){
        if (((*pP).pos[idxCurrentPlayer]) == (TELEPORT_LAYOUT(*CurrentMap)[IdxTeleIn])){
            isTeleport = TRUE;
        }
        IdxTeleIn += 2;
    }

    if (isTeleport == TRUE){
        int IdxTeleIn = 0;
        int IdxTeleOut = 1;
        printf("Oops, kamu berada pada teleport!\n");
        if ((*pT).isTele[idxCurrentPlayer] == TRUE){
            printf("Kamu tidak berpindah karena sudah terkena teleport sebelumnya!\n");
        }
        if ((*pT).isTele[idxCurrentPlayer] == FALSE){
            char use[15];
            if((*pI).isImun[idxCurrentPlayer] == TRUE) {
                printf("Pakai anti-teleport (Y/N): \n");
                scanf("%s", use);
                if(strcmp(use, "N")==0) {
                    for(int i = 0; i < TELEPORT_COUNT(*CurrentMap); i++){
                        if (((*pP).pos[idxCurrentPlayer]) == (TELEPORT_LAYOUT(*CurrentMap)[IdxTeleIn])){
                            (*pT).isTele[idxCurrentPlayer] = TRUE;
                            (*pP).pos[idxCurrentPlayer] = TELEPORT_LAYOUT(*CurrentMap)[IdxTeleOut];
                        }
                    IdxTeleIn += 2;
                    IdxTeleOut += 2;
                    }
                } else if(strcmp(use, "Y")==0) {
                    printf("Kamu memakai anti-teleport sehingga posisi Anda tidak berubah\n");
                    (*pI).isImun[idxCurrentPlayer] = FALSE;
                } 
            }
            else {
                printf("Kamu tidak memiliki anti-teleport, posisi Anda akan dipindahkan \n");
                for(int i = 0; i < TELEPORT_COUNT(*CurrentMap); i++){
                    if (((*pP).pos[idxCurrentPlayer]) == (TELEPORT_LAYOUT(*CurrentMap)[IdxTeleIn])){
                        (*pT).isTele[idxCurrentPlayer] = TRUE;
                        (*pP).pos[idxCurrentPlayer] = TELEPORT_LAYOUT(*CurrentMap)[IdxTeleOut];
                    }
                    IdxTeleIn += 2;
                    IdxTeleOut += 2;
                };
            }
        }

        printf("Anda sekarang berada pada posisi ");
        printf("%d ", (*pP).pos[idxCurrentPlayer]);
        printf("\n");
    } 
    else{
        printf("Tidak ada teleport pada petak tersebut\n");
    }
}
