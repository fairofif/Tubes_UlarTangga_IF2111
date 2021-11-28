#include "load.h"

void main(){
    
    int banyakPemain;
    int round; 
    pUserName pU;
    pIsTeleported pT;
    pIsImune pI;
    pPosition pP;
    pIsCermin pC;
    pIsSenterBesar pSB;
    pIsSenterKecil pSK;
    Skill pS1, pS2, pS3, pS4;
    Round R;
    Map CurrentMap;
    char configmap[20];

    createEmptyRound(&R);
    Load(&banyakPemain, configmap, &round, &pU, &pT, &pP, &pI, &pC, &pSB, &pSK, &pS1, &pS2, &pS3, &pS4);
    
    loadConfig(&CurrentMap, configmap);
    for(int i = 0; i < 20; i++ ){
        (*fileconfig)[i] = configmap[i];
    }
    printConfig(&CurrentMap);

}
