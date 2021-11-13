#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../boolean.h"
#include "map.h"

Map CurrentMap;
int *petak, *maxroll, *telcount;

void readConfig()
{
    printf("EndKata awal %d\n", EndKata); //PRINTF   
    printf("masuk ke readconfig\n"); //PRINTF
    STARTKATA(); // 2
    printf("EndKata %d\n", EndKata); //PRINTF
    while(!EndKata) {
        printf("masuk ke advkata\n"); //PRINTF
        ADVKATA(); // 5
        printf("EndKata setelah adv kata %d\n", EndKata); //PRINTF
    }
}

void inputConfig() 
{
    char namafile[254] = "map1.txt";
    char *dummy = "map1.txt";
    boolean valid = FALSE;

    while(!valid){
        // scanf("%s", namafile);
        if(strcmp(namafile, dummy) == 0) { //ini masih harus ditanya boleh pake strcmp ngga
            fileconfig = &namafile;
            printf("masuk ke fileconfig diganti %s\n", *fileconfig); //PRINTF
            valid = TRUE;
        } else {
            printf("Masukkan file config salah.\n"); //PRINTF
        }
    }
    printf("masuk ke inputconfig\n"); //PRINTF
    readConfig();
}

