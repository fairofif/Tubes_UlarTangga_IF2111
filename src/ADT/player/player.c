#include "player.h"
#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

void createEmptyPlayerList (pUserName *pU) {
    (*pU).Neff = 0;
}

void createEmptyPlayerSkillsList (Skill *S) {
    ADDR_HEADSKILL(*S) = Nil;
}

address newSkillNode () {
    lsNode *P = (lsNode *)malloc(sizeof(lsNode));
    if (P != Nil) {
        NEXTSKILL(P) = Nil;
        strcpy(SKILLNAME(P), "kosong");
        return P;
    }
    else {
        return Nil;
    }
}

void preparationSkillList (Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4, int n) {
    for (int i = 1; i <= n ; i ++) {
        if (i == 1) {
            createEmptyPlayerSkillsList(pS1);
        }
        else if (i == 2) {
            createEmptyPlayerSkillsList(pS2);
        }
        else if (i == 3) {
            createEmptyPlayerSkillsList(pS3);
        }
        else if (i == 4) {
            createEmptyPlayerSkillsList(pS4);
        }
    }
}

void summonPlayer (pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC, pIsSenterBesar *pSB, pIsSenterKecil *pSK, int n) {
    for (int i = 1 ; i <= n ; i++) {
        printf("coba masukin uname\n");
        scanf("%s", &((*pU).uname[i]));
        (*pT).isTele[i] = FALSE;
        (*pP).pos[i] = 1;
        (*pI).isImun[i] = FALSE;
        (*pC).isCermin[i] = FALSE;
        (*pSB).isSenterBesar[i] = FALSE;
        (*pSK).isSenterKecil[i] = FALSE;
    }
    (*pU).Neff = n;
}

int getIdxOfPlayer(pUserName pU, char *name) {
    int i = IdxMin;
    char temp[16];
    strcpy(temp, name);
    while ((strcmp(pU.uname[i], temp) != 0) && (i <= IdxMax)) {
        ++i;
    }
    if (i <= IdxMax) {
        return i;
    }
    else {
        return IdxUndef;
    }
}

boolean isEmptyList (Skill pS) {
    return ((ADDR_HEADSKILL(pS)) == Nil);
}

void insertVSkill (Skill *pS, char *skname) {
    if (isEmptyList(*pS)) {
        address P = newSkillNode();
        strcpy(SKILLNAME(P), skname);
        NEXTSKILL(P) = Nil;
        ADDR_HEADSKILL(*pS) = P;
    }
    else {
        address P = ADDR_HEADSKILL(*pS);
        int count = 1;
        while ((NEXTSKILL(P) != Nil) && (count <= 10)) {
            count++;
            P = NEXTSKILL(P);
        }
        if (count <= 10) {
            address X = newSkillNode();
            strcpy(SKILLNAME(X), skname);
            NEXTSKILL(X) = Nil;
            NEXTSKILL(P) = X;
        }
    }
}

boolean getTeleportedConditionOfPlayer(pIsTeleported pT, pUserName pU, char *uname) {
    int idx = getIdxOfPlayer(pU, uname);
    if (idx != IdxUndef) {
        return (pT.isTele[idx]);
    }
}

boolean getImmunityConditionOfPlayer (pIsImune pI, pUserName pU, char *uname) {
    int idx = getIdxOfPlayer(pU, uname);
    if (idx != IdxUndef) {
        return (pI.isImun[idx]);
    }
}

int getPositionOfPlayer (pPosition pP, pUserName pU, char *uname) {
    int idx = getIdxOfPlayer(pU, uname);
    if (idx != IdxUndef) {
        return (pP.pos[idx]);
    }
}

boolean getCerminConditionOfPlayer (pIsCermin pC, pUserName pU, char *uname) {
    int idx = getIdxOfPlayer(pU, uname);
    if (idx != IdxUndef) {
        return (pC.isCermin[idx]);
    }
}

boolean getSenterBesarConditionOfPlayer (pIsSenterBesar pSB, pUserName pU, char *uname) {
    int idx = getIdxOfPlayer(pU, uname);
    if (idx != IdxUndef) {
        return (pSB.isSenterBesar[idx]);
    }
}

boolean getSenterKecilConditionOfPlayer (pIsSenterKecil pSK, pUserName pU, char *uname) {
    int idx = getIdxOfPlayer(pU, uname);
    if (idx != IdxUndef) {
        return (pSK.isSenterKecil[idx]);
    }
}