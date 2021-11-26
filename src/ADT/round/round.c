#include "round.h"

void createEmptyRound (Round *R) {
    LATESTROUND(*R) = Nil;
}

addressRound newRoundNode () {
    RoundNode *P = (RoundNode *)malloc(sizeof(RoundNode));
    if (P != Nil) {
        for (int i = 1; i <= 4 ; i++) {
            (POSITIONROUND(P))[i] = 0;
            (TELEPORTEDROUND(P))[i] = FALSE;
            (IMUNITYROUND(P))[i] = FALSE;
            (CERMINROUND(P))[i] = FALSE;
            (SENTERBROUND(P))[i] = FALSE;
            (SENTERKROUND(P))[i] = FALSE;
            for (int j = 1; j <= 10 ; j ++) {
                strcpy(((SKILLROUND(P))[i][j]), "");
            }
        }
        (NEXTROUND(P)) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}

void pushRound (Round *R, pPosition pP, pIsTeleported pT, pIsImune pI,
pIsCermin pC, pIsSenterBesar pSB, pIsSenterKecil pSK, Skill pS1,
Skill pS2, Skill pS3, Skill pS4, int nPlayer) {
    int nSkill;
    char skname[30];
    addressRound P = newRoundNode();
    if (LATESTROUND(*R) != Nil) {
        NEXTROUND(P) = LATESTROUND(*R);
        LATESTROUND(*R) = P;
    }
    else {
        LATESTROUND(*R) = P;
    }
    P = LATESTROUND(*R);

    for (int i = 1; i <= nPlayer; i++) {
        (POSITIONROUND(P))[i] = getPositionOfPlayer(pP, i);
        (TELEPORTEDROUND(P))[i] = getTeleportedConditionOfPlayer(pT, i);
        (IMUNITYROUND(P))[i] = getImmunityConditionOfPlayer(pI, i);
        (CERMINROUND(P))[i] = getCerminConditionOfPlayer(pC, i);
        (SENTERBROUND(P))[i] = getSenterBesarConditionOfPlayer(pSB, i);
        (SENTERKROUND(P))[i] = getSenterKecilConditionOfPlayer(pSK, i); 
        nSkill = banyaknyaSkill(pS1, pS2, pS3, pS4, i);
        for (int j = 1; j <= nSkill; j++) {
            strcpy(skname, "");
            copySkillName(pS1,pS2,pS3,pS4,i,j,&skname);
            strcpy((SKILLROUND(P))[i][j], skname);
        }
    
    }
}

void undoRound (Round *R, pPosition *pP, pIsTeleported *pT, pIsImune *pI,
pIsCermin *pC, pIsSenterBesar *pSB, pIsSenterKecil *pSK, Skill *pS1,
Skill *pS2, Skill *pS3, Skill *pS4, int nPlayer) {
    addressRound P = LATESTROUND(*R);
    int nSkill;
    char skname[30];
    for (int i = 1; i <= nPlayer; i++) {
        (*pP).pos[i] = (POSITIONROUND(P))[i];
        (*pT).isTele[i] = (TELEPORTEDROUND(P))[i];
        (*pI).isImun[i] = (IMUNITYROUND(P))[i];
        (*pC).isCermin[i] = (CERMINROUND(P))[i];
        (*pSB).isSenterBesar[i] = (SENTERBROUND(P))[i];
        (*pSK).isSenterKecil[i] = (SENTERKROUND(P))[i];
        nSkill = banyaknyaSkill(*pS1,*pS2,*pS3,*pS4,i);
        if (i == 1) {
            createEmptyPlayerSkillslList(pS1);
            for (int j = 1; j <= nSkill; j++) {
                strcpy(skname, "");
                strcpy(skname, (SKILLROUND(P))[i][j]);
                insertVSkill(pS1, skname);
            }
        }
        else if (i == 2) {
            createEmptyPlayerSkillslList(pS2);
            for (int j = 1; j <= nSkill; j++) {
                strcpy(skname, "");
                strcpy(skname, (SKILLROUND(P))[i][j]);
                insertVSkill(pS2, skname);
            }
        }
        else if (i == 3) {
            createEmptyPlayerSkillslList(pS3);
            for (int j = 1; j <= nSkill; j++) {
                strcpy(skname, "");
                strcpy(skname, (SKILLROUND(P))[i][j]);
                insertVSkill(pS3, skname);
            }
        }
        else if (i == 4) {
            createEmptyPlayerSkillslList(pS4);
            for (int j = 1; j <= nSkill; j++) {
                strcpy(skname, "");
                strcpy(skname, (SKILLROUND(P))[i][j]);
                insertVSkill(pS4, skname);
            }
        }
    }
    LATESTROUND(*R) = NEXTROUND(P);
    free(P);
}
