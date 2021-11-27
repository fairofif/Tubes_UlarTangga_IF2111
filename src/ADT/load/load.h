#ifndef _LOAD_H
#define _LOAD_H

#include "../../console.h"

void Load(int *banyakPemain, int *round, pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC,
pIsSenterBesar *pSB, pIsSenterKecil *pSK, Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4);
/*  Me-load kondisi game yang sudah disimpan sebelumnya
    n: jumlah player */

int IsfFileExists(char *filename);

void unshortenSkillName(char skillName[]);

#endif