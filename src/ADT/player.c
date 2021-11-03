#include "player.h"
#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

void createEmptyPlayerList (Player *PL) {
    ADDR_FIRSTPLAYER(*PL) = Nil;
}

void createEmptyPlayerSkillsList (pSkill *PR) {
    ADDR_FIRSTSKILL(*PR) = Nil;
}

address newSkillNode () {
    lsNode *P = (lsNode *)malloc(sizeof(lsNode));
    if (P != Nil) {
        NEXTSKILL(P) = Nil;
        SKILLNAME(P) = "";
        return P;
    }
    else {
        return Nil;
    }
}

address newPlayerNode () {
    pNode *P = (pNode *)malloc(sizeof(pNode));
    if (P != Nil) {
        POS(P) = 0;
        ISTELE(P) = FALSE;
        ISIMMUNE(P) = FALSE;
        NEXT(P) = Nil;
        ADDR_FIRSTSKILL(SKILLS(P)) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}

void inputPlayerList (Player *PL, int n) {
    createEmptyPlayerList(&PL);
    address P = ADDR_FIRSTPLAYER(*PL);
    address node;
    for (int i = 1; i <= n; i++) {
        node = newPlayerNode();
        P = node;
        printf("Nama Player ke %d: ", n);
        scanf("%s", &(PNAME(P)));
        P = NEXT(P);
    }
    P = ADDR_FIRSTPLAYER(*PL);
}

void getFirstSkill (Player *PL, address playerWhoGetSkill) {
    address P = ADDR_FIRSTPLAYER(*PL);
    while (P != playerWhoGetSkill) {
        P = NEXT(P);
    }   
    pSkill PS;
    createEmptyPlayerSkillsList(&PS);
    SKILLS(P) = PS;
    address PLS = ADDR_FIRSTSKILL(SKILLS(P));
    while (PLS != Nil) {
        PLS = NEXTSKILL(PLS);
    }
    address node = newSkillNode();
    SKILLNAME(node) = randomSkillGenerator();
    PLS = node;
}