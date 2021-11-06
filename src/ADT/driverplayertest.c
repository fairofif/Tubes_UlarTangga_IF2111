#include "player.h"
#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
    pUserName pU;
    pIsImune pI;
    pIsTeleported pT;
    pPosition pP;
    Skill pS1, pS2, pS3, pS4;
    

    printf("mau masukin berapa player: ");
    int n;
    scanf("%d", &n);
    preparationSkillList(&pS1, &pS2, &pS3, &pS4, n);    
    createEmptyPlayerList(&pU);
    summonPlayer(&pU,&pT,&pP,&pI,n);
    
    char uname[16];
    char skname[25];
    int idxP;
        
    printf("cobain masukin skill di username siapa: ");
    scanf("%s", &uname);
   
 
    idxP = getIdxOfPlayer(pU, uname);
    
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
    insertVSkill(&pS2, "testaja");
    insertVSkill(&pS2, skname);
    insertVSkill(&pS2, "ini juga sih");

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
}