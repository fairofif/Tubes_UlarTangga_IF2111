#include "player.h"
#include "../boolean.h"
#include "player.c"
# include <stdio.h>
# include "boolean.h"

// ini buat nanti dicopas ke main drivernya
int main(){
    char s[15];
    int count = 0;
    if (getTeleportedConditionOfPlayer){
        if(getImmunityConditionOfPlayer){
            printf("Apakah ingin menggunakan imun?\n");
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
int teleport (pPosition pP, pUserName pU, char *uname){
    int idx = getIdxOfPlayer(pU, uname);
    if (idx != IdxUndef) {
        /* Teleport maju */
        if (pP.pos[idx] == 1){
            pP.pos[idx] = 24;
            return (pP.pos[idx]);
        }
        else if (pP.pos[idx] == 12){
            pP.pos[idx] = 48;
            return (pP.pos[idx]);
        }
        else if (pP.pos[idx] == 42){
            pP.pos[idx] = 66;
            return (pP.pos[idx]);
        }
        else if (pP.pos[idx] == 58){
            pP.pos[idx] = 72;
            return (pP.pos[idx]);
        }
        else if (pP.pos[idx] == 85){
            pP.pos[idx] = 93;
            return (pP.pos[idx]);
        }
        /* Teleport mundur*/
        else if (pP.pos[idx] == 28){
            pP.pos[idx] = 16;
            return (pP.pos[idx]);
        }
        else if (pP.pos[idx] == 50){
            pP.pos[idx] = 25;
            return (pP.pos[idx]);
        }
        else if (pP.pos[idx] == 71){
            pP.pos[idx] = 60;
            return (pP.pos[idx]);
        }
        else if (pP.pos[idx] == 91){
            pP.pos[idx] = 59;
            return (pP.pos[idx]);
        }
        else if (pP.pos[idx] == 96){
            pP.pos[idx] = 89;
            return (pP.pos[idx]);
        }
    }
}
