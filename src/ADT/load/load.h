#ifndef _LOAD_H
#define _LOAD_H

#include "../../boolean.h"
#include "../player/player.h"
#include "../mesinkata/mesin_kata.h"
#include "../mesinkar/mesin_kar.h"

void Load(int n, pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC,
pIsSenterBesar *pSB, pIsSenterKecil *pSK, Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4);
/*  Me-load kondisi game yang sudah disimpan sebelumnya
    n: jumlah player */

#endif