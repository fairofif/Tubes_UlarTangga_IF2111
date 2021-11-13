#include "map.h"

Map CurrentMap;
int inputIndicator = 1; //teleport indikator (mengindikasikan input berupa telport)


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
        inputIndicator++;
        ADVKATA(); // 5
    }
}

void assignConfig()
{
    if(inputIndicator == 2) {
        CurrentMap.ConfigMap.LayoutLength = CKata.Length;
        for(int i = 1; i <= CKata.Length; i++) {
            CurrentMap.ConfigMap.Layout[i] = CKata.TabKata[i];
            printf("%c", CurrentMap.ConfigMap.Layout[i]);
        }
        printf("\n");
        //CEK DULU IF C.LENGTHNYA SAMA KAYA LENGTH
    } else {
        int value = 0;
        int n = CKata.Length;
        if(inputIndicator > 4) {
            int j = 0;
            n = 0;
            for(int i = CKata.Length; i > 0; i--) {
                if(CKata.TabKata[i] == BLANK) {
                    value = 0;
                    n = 0;
                } else {
                    int temp = chartoint(CKata.TabKata[i]);
                    value = value + (temp * pow(10, n));
                    CurrentMap.Teleport.TeleportLayout[j] = value;
                    j++; //CEK SAMA KAYA TELEPORTCOUNT NGGA
                    n++;
                }
            }
            printf("%d %d\n", CurrentMap.Teleport.TeleportLayout[j-1], CurrentMap.Teleport.TeleportLayout[j-2]);   
        } else {
            for(int i = 1; i <= CKata.Length; i++) {
                int temp = chartoint(CKata.TabKata[i]);
                value = value + (temp * pow(10, n-i));
                if(inputIndicator == 1) {
                    CurrentMap.MapLength = value;
                } else if(inputIndicator == 3) {
                    CurrentMap.MaxRoll = value;
                } else if(inputIndicator == 4) {
                    CurrentMap.Teleport.TeleportCount = value;
                }
        }
        } 
    }
}