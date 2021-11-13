#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../boolean.h"
#include "map.h"


void inputConfig() 
{
    char namafile[254] = "map1.txt";
    char *dummy = "map1.txt";
    boolean valid = FALSE;

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
        ADVKATA(); // 5
    }
    assignConfig();
}

void assignConfig()
{
    Map *CurrentMap;
    for (int i = 1; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]);
    }
}
