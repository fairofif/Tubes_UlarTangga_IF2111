#include "../../console.h"
#include "getmap.h"

void getfileconfig()
{   
    Map CurrentMap;
    char namafile[254];
    boolean valid = FALSE;
    while(!valid){
        printf("\nKONFIGURASI MAP YANG TERSEDIA : \n\n1.RAT-RACE(rat-race.txt) -> Difficulty 9/10, Fun 3/10\n2.FLOOR-ISLAVA(lavafloor.txt) -> Difficulty 6/10, Fun 7/10\n\n"); 
        printf("Masukkan file config txt : ");
        scanf("%s", namafile);
        if((strcmp(namafile, "ratrace.txt") == 0) || (strcmp(namafile, "lavafloor.txt") == 0)) {
            fileconfig = &namafile;
            valid = TRUE;
        } else {
            printf("\nMasukkan salah!");
            printf("\nKONFIGURASI MAP YANG TERSEDIA : \n\n1.RAT-RACE(rat-race.txt) -> Difficulty 9/10, Fun 3/10\n2.FLOOR-ISLAVA(lavafloor.txt) -> Difficulty 6/10, Fun 7/10\n\n"); 
        }
    }
}
