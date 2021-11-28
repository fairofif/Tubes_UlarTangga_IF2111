#include "../../console.h"
#include "../../boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int main () {
    pUserName pU;
    pIsImune pI;
    pIsTeleported pT;
    pPosition pP;
    pIsCermin pC;
    pIsSenterBesar pSB;
    pIsSenterKecil pSK;
    Skill pS1, pS2, pS3, pS4;
   
    printf("TESTING DRIVER PLAYER\n\n");
    printf("mau masukin berapa player: ");
    int n;
    scanf("%d", &n);
    preparationSkillList(&pS1, &pS2, &pS3, &pS4, n);    
    createEmptyPlayerList(&pU);
    summonPlayer(&pU,&pT,&pP,&pI,&pC,&pSB,&pSK, n);
 
    char uname[16];
    char skname[30];
    int idxP;
    int nSkill;

    boolean stopisi = 0;
    char pilihan[5];
 
    while (!stopisi) {    
        printf("cobain masukin skill di username siapa: ");
        scanf("%s", &uname);
        srand(time(0));
        strcpy(skname, "");
        randomSkillGenerator(skname);
        printf("skill %s ditambahin ke player %s\n", skname, uname);
   
        idxP = getIdxOfPlayer(pU, uname);
        printf("index %d\n", idxP);
       
        
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
        printf("Banyaknya skill %s ada %d buah skill\n", uname, banyaknyaSkill(pS1, pS2, pS3, pS4, idxP));
        printSkill(pS1, pS2, pS3, pS4, idxP, &nSkill);
        
        printf("masih mau nyoba print skill (ya/no) ? ");
        scanf("%s", &pilihan);
        if (strcmp(pilihan, "no")== 0) {
            stopisi = 1;
        }
        strcpy(pilihan, "");
        strcpy(uname, "");
    }

    printf("\nIni buat ngetes check player condition\n");
    for (int i = 1; i<=n ; i++) {
        printf("nama player: %s\n", pU.uname[i]);
        printf("posisi: %d\n", getPositionOfPlayer(pP, i));
        printf("Apakah baru terkena teleport: %d\n", getTeleportedConditionOfPlayer(pT,i));
        printf("Buff imune: %d\n", getImmunityConditionOfPlayer(pI,i));
        printf("Buff Cermin: %d\n", getCerminConditionOfPlayer(pC, i));
        printf("Buff Senter Kecil: %d\n", getSenterBesarConditionOfPlayer(pSB, i));
        printf("Buff Senter Kecil: %d\n\n", getSenterBesarConditionOfPlayer(pSB, i));
        

    }


}