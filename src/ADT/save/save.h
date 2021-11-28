#ifndef _SAVE_H
#define _SAVE_H

#include "../../boolean.h"
#include "../player/player.h"

void Save(int n, int round, char mapname[], pUserName pU, pIsTeleported pT, pPosition pP, pIsImune pI, pIsCermin pC,
pIsSenterBesar pSB, pIsSenterKecil pSK, Skill pS1, Skill pS2, Skill pS3, Skill pS4); 
/*  Menyimpan kondisi player di tengah permainan.
    I.S. : n, round, pU, pT, pP, pI, pC, pSB, pSK, pS1, pS2, pS3, pS4 terdefinisi
    F.S. : info n, round, pU, pT, pP, pI, pC, pSB, pSK, pS1, pS2, pS3, pS4 player disimpan dalam file teks
    n: jumlah player */


void shortenSkillName(char skillName[]);
/* Memnbuat nama skill menjadi digabung tanpa BLANK
    I.S. : nama skill terdefinisi
    F.S. : nama skill menjadi satu kata */

#endif