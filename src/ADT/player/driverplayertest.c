#include "player.h"
#include "../../boolean.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
    pUserName pU;
    pIsImune pI;
    pIsTeleported pT;
    pPosition pP;
    pIsCermin pC;
    pIsSenterBesar pSB;
    pIsSenterKecil pSK;
    Skill pS1, pS2, pS3, pS4;
    

    printf("mau masukin berapa player: ");
    int n;
    scanf("%d", &n);
    preparationSkillList(&pS1, &pS2, &pS3, &pS4, n);    
    createEmptyPlayerList(&pU);
    summonPlayer(&pU,&pT,&pP,&pI,&pC,&pSB,&pSK,n);

    char uname[16];
    char skname[25];
    int idxP;
    
    boolean stopisi = 0;
    char pilihan[5];

    while (!stopisi) {    
        printf("cobain masukin skill di username siapa: ");
        scanf("%s", &uname);
    
    
        idxP = getIdxOfPlayer(pU, uname);
        printf("index %d\n", idxP);
        
        printf("nama skillnya mau apa: ");
        scanf("%s", &skname);
        if (idxP == 1) {
            insertVSkill(&pS1, skname);
        } 
        else if (idxP == 2) {
            insertVSkill(&pS2, skname);
        }
        else if (idxP == 3) {
            insertVSkill(&pS3, skname);
        }
        else if (idxP == 4) {
            insertVSkill(&pS4, skname);
        }


        printf("masih mau nyoba ngisi skill (ya/no) ? ");
        scanf("%s", &pilihan);
        if (strcmp(pilihan, "no")==0) {
            stopisi = 1;
        }
        strcpy(pilihan, "");
        strcpy(uname, "");
        strcpy(skname, "");
    }

    stopisi = 0;

    while (!stopisi) {
        printf("mau nyoba print skill user siapa?");
        scanf("%s", &uname);
        
        idxP = getIdxOfPlayer(pU, uname);
        if (idxP == 1) {
            address P = ADDR_HEADSKILL(pS1);
            while (P != Nil) {
                printf("%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        else if (idxP == 2) {
            address P = ADDR_HEADSKILL(pS2);
            while (P != Nil) {
                printf("%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        else if (idxP == 3) {
            address P = ADDR_HEADSKILL(pS3);
            while (P != Nil) {
                printf("%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        else if (idxP == 4) {
            address P = ADDR_HEADSKILL(pS4);
            while (P != Nil) {
                printf("%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        printf("Anda sekarang berada pada posisi ", pP.pos[idxP], "\n");
        printf("masih mau nyoba print skill (ya/no) ? ");
        scanf("%s", &pilihan);
        if (strcmp(pilihan, "no")== 0) {
            stopisi = 1;
        }
        strcpy(pilihan, "");
        strcpy(uname, "");
    }    

    // Ini main buat di teleport
    char s[15];
    int count = 0;
    printf("Oops, Anda berada pada teleport!\n");
    if (getTeleportedConditionOfPlayer){
        if(getImmunityConditionOfPlayer){
            printf("Apakah ingin menggunakan imun? (yes/no)\n");
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

// Ini prosedur teleportnya gue pindahin ke sini biar gampang, tp nanti kalo mau apus gapapa soalnya aslinya ada di file teleport.c
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