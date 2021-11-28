#ifndef _LOAD_H
#define _LOAD_H

#include "../../console.h"

void Load(int *banyakPemain, char *configmap, int *round, pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC,
pIsSenterBesar *pSB, pIsSenterKecil *pSK, Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4);
/*  Me-load kondisi game yang sudah disimpan sebelumnya
    n: jumlah player */

boolean IsFileExists(char *filename);
/*  Mengecek apakah file save ditemukan 
    F.S. : TRUE jika file ditemukan, FALSE jika tidak ditemukan */

void unshortenSkillName(char skillName[]);
/*  Mengubah nama skill dari file save menjadi nama sebenarnya
    F.S. : nama skill menjadi nama sebenarnya, tiap kata dipisah dengan BLANK */

#endif