#include "map.h"

Map CurrentMap;

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
}

void assignConfig()
{
    if(CKata.TabKata[1] == '.') {
        CurrentMap.ConfigMap.LayoutLength = CKata.Length;
        for(int i = 1; i <= CKata.Length; i++) {
            CurrentMap.ConfigMap.Layout[i] = CKata.TabKata[i];
            printf("%c", CurrentMap.ConfigMap.Layout[i]);
        }
        printf("\n");
        //CEK DULU IF C.LENGTHNYA SAMA KAYA LENGTH
    } else {
        for(int i = 1; i <= CKata.Length; i++) {
            int value = 0;
            int temp = chartoint(CKata.TabKata[i]);
            IgnoreBlank();
        }
    }
}
