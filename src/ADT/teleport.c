#include "player.h"
#include "../boolean.h"
#include "player.c"
# include <stdio.h>
# include "boolean.h"

// ini buat nanti dicopas ke main drivernya
int main(){
    char s[15];
    int count = 0;
    printf("Oops, Anda berada pada teleport!\n");
    if (getTeleportedConditionOfPlayer){
        if(getImmunityConditionOfPlayer){
            printf("Apakah ingin menggunakan imun (yes/no)? \n");
            scanf("%s",s);
            if (strcmp(s, "no") == 0){
                count++;
            }
        else if (!getImmunityConditionOfPlayer){
            count++;
            }
        }
    }

    if (count == 1){
        teleport(pP, pU, uname);
    }
}

// ini function si teleportnya
void teleport (pPosition pP, pUserName pU, char *uname){
    int idxP;
    idxP = getIdxOfPlayer(pU, uname);
    /* Teleport maju */
    if (pP.pos[idxP] == 1){
        pP.pos[idxP] = 24;
    }
    else if (pP.pos[idxP] == 12){
        pP.pos[idxP] = 48;
    }
    else if (pP.pos[idxP] == 42){
        pP.pos[idxP] = 66;
    }
    else if (pP.pos[idxP] == 58){
        pP.pos[idxP] = 72;
    }
    else if (pP.pos[idxP] == 85){
        pP.pos[idxP] = 93;
    }
    /* Teleport mundur*/
    else if (pP.pos[idxP] == 28){
        pP.pos[idxP] = 16;
    }
    else if (pP.pos[idxP] == 50){
        pP.pos[idxP] = 25;
    }
    else if (pP.pos[idxP] == 71){
        pP.pos[idxP] = 60;
    }
    else if (pP.pos[idxP] == 91){
        pP.pos[idxP] = 59;
    }
    else if (pP.pos[idxP] == 96){
        pP.pos[idxP] = 89;
    }
    printf("Anda sekarang berada pada posisi ", pP.pos[idxP], "\n");
}