#include "player.h"
#include "../../boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
 
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
        strcpy(SKILLNAME(P), "");
        return P;
    }
    else {
        return Nil;
    }
}
 
void randomSkillGenerator(char *skname) {
    char skill[8][30] = {"Pintu Ga Ke Mana Mana",
                        "Mesin Waktu",
                        "Baling Baling Jambu",
                        "Cermin Pengganda",
                        "Senter Pembesar Hoki",
                        "Senter Pengecil Hoki",
                        "Mesin Penukar Posisi",
                        "Teknologi Gagal" };
    int arrIDX[100];
    for (int i = 0 ; i <= 99 ; i++) {
        if (i >= 0 && i <= 9) {
            arrIDX[i] = 0;
        }
        else if (i >= 10 && i <= 19) {
            arrIDX[i] = 1;
        }
        else if (i >= 20 && i <= 29) {
            arrIDX[i] = 2;
        }
        else if (i >= 30 && i <= 35) {
            arrIDX[i] = 3;
        }
        else if (i >= 36 && i <= 50) {
            arrIDX[i] = 4;
        }
        else if (i >= 51 && i <= 65) {
            arrIDX[i] = 5;
        }
        else if (i >= 66 && i <= 69) {
            arrIDX[i] = 6;
        }
        else {
            arrIDX[i] = 7;
        }
    }
 
    int idx = randomInt99();
    int idxSkill = arrIDX[idx];
    strcpy(skname, skill[idxSkill]);
}
 
int randomInt99() {
    int idx;
    time_t t1;
 
    srand ( (unsigned) time (&t1));
 
    idx = rand() % 100;
   
    return idx;
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
 
void printSkill (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, int *nSkill) {
    /* nSkill itu output, secara ga langsung dia ngitung jumlah skill */
    address P;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(pS4);
    }
    int i = 0;
    while (P != Nil) {
        i++;
        printf("%d. %s\n", i, SKILLNAME(P));
        P = NEXTSKILL(P);
    }
    /* nSkill itu output, secara ga langsung dia ngitung jumlah skill */
    /* jadi ntar si nSkill dipake buat batas angka inputan si user,
        biar ga usah pake 2 prosedur */
    *nSkill = i;
}
 
int banyaknyaSkill (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP) {
    address P;
    int count = 0;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(pS4);
    }
    while (P != Nil) {
        count++;
        P = NEXTSKILL(P);
    }
    return count;
}
 
int returnIdxSkill (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, char *skName) {
    address P;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(pS4);
    }
 
    char temp[30];
    int idxS = 1;
    strcpy(temp, skName);
    boolean found = FALSE;
    while ((P != Nil) && (!found)) {
        if (strcmp(SKILLNAME(P), temp) == 0) {
            found = TRUE;
        }
        else {
            idxS++;
            P = NEXTSKILL(P);
        }
    }
    if (found) {
        return idxS;
    }
    else {
        return IdxUndef;
    }
}
 
boolean isSkillExists (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, char *skName) {
    address P;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(pS4);
    }
 
    char temp[30];
    strcpy(temp, skName);
    boolean found = FALSE;
    while ((P != Nil) && (!found)) {
        if (strcmp(SKILLNAME(P), temp) == 0) {
            found = TRUE;
        }
        else {
            P = NEXTSKILL(P);
        }
    }
    return found;
}
 
void deleteSkill (Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4, int idxP, int idxS) {
    address P;
    address Prec;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(*pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(*pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(*pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(*pS4);
    }
   
    if (idxS != 1) {
        Prec = P;
        P = NEXTSKILL(P);
        int idx = 2;
        while ((idx != idxS) && (P != Nil)) {
            idx++;
            Prec = NEXTSKILL(Prec);
            P = NEXTSKILL(P);
        }
        NEXTSKILL(Prec) = NEXTSKILL(P);
        NEXTSKILL(P) = Nil;
        free(P);
    }
    else {
        if (idxP == 1) {
            ADDR_HEADSKILL(*pS1) = NEXTSKILL(P);
            NEXTSKILL(P) = Nil;
            free(P);
        }
        else if (idxP == 2) {
            ADDR_HEADSKILL(*pS2) = NEXTSKILL(P);
            NEXTSKILL(P) = Nil;
            free(P);
        }
        else if (idxP == 3) {
            ADDR_HEADSKILL(*pS3) = NEXTSKILL(P);
            NEXTSKILL(P) = Nil;
            free(P);
        }
        else if (idxP == 4) {
            ADDR_HEADSKILL(*pS4) = NEXTSKILL(P);
            NEXTSKILL(P) = Nil;
            free(P);
        }
    }
}
 
void summonPlayer (pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC,
pIsSenterBesar *pSB, pIsSenterKecil *pSK, int n) {
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
 
boolean getTeleportedConditionOfPlayer(pIsTeleported pT, int idx) {
    if (idx != IdxUndef) {
        return (pT.isTele[idx]);
    }
}
 
boolean getImmunityConditionOfPlayer (pIsImune pI, int idx) {
    if (idx != IdxUndef) {
        return (pI.isImun[idx]);
    }
}
 
int getPositionOfPlayer (pPosition pP, int idx) {
    if (idx != IdxUndef) {
        return (pP.pos[idx]);
    }
}
 
boolean getCerminConditionOfPlayer (pIsCermin pC, int idx) {
    if (idx != IdxUndef) {
        return (pC.isCermin[idx]);
    }
}
 
boolean getSenterBesarConditionOfPlayer (pIsSenterBesar pSB, int idx) {
    if (idx != IdxUndef) {
        return (pSB.isSenterBesar[idx]);
    }
}
 
boolean getSenterKecilConditionOfPlayer (pIsSenterKecil pSK, int idx) {
    if (idx != IdxUndef) {
        return (pSK.isSenterKecil[idx]);
    }
}

void copySkillName (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, int idxSkill, char *skname) {
    address P;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(pS4);
    }
    int i = 1;
    while (i != idxSkill) {
        P = NEXTSKILL(P);
        i++;
    }
    strcpy(skname, SKILLNAME(P));
}