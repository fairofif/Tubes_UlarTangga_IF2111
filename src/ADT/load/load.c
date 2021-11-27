#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"
#include "../map/map.h"

void Load(int n, pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC,
pIsSenterBesar *pSB, pIsSenterKecil *pSK, Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4){
// KAMUS
    int i, jmlskill, j, k; 
    char filename[100];

// ALGORITMA

    printf("Masukkan nama save file yang ingin diload: ");
    scanf("%s", filename);
    
    FILE *pfile;
    
    if ((pfile = fopen(filename, "r")) == NULL){
        printf("Error: File tidak ada!");
        exit(1);
    }

    // Load kondisi player
    for (i=1; i<=n; i++){
        printf("loop data status player\n");

        (*pP).pos[i] = KataToInt(CKata);
        ADVKATA2();
        (*pT).isTele[i] = KataToInt(CKata);
        ADVKATA2();
        (*pI).isImun[i] = KataToInt(CKata);
        ADVKATA2();
        (*pC).isCermin[i] = KataToInt(CKata);
        ADVKATA2();
        (*pSB).isSenterBesar[i] = KataToInt(CKata);
        ADVKATA2();
        (*pSK).isSenterKecil[i] = KataToInt(CKata);
        ADVKATA2();
    }

    // Load skill
    for (i=1; i<=n; i++){
        printf("masuk loop skill\n");
        jmlskill = KataToInt(CKata); ADVKATA2();
        if (i == 1){
            for (j=1; j <= jmlskill; j++){ // loop sebanyak jml skill di satu uname
                char skill1[30];
                for (k=1; k <= CKata.Length; k++){
                    skill1[k-1] = CKata.TabKata[k];
                }
                insertVSkill(pS1, *skill1);
                ADVKATA2();
            }
        }
        else if (i == 2){
            for (j=1; j <= jmlskill; j++){ // loop sebanyak jml skill di satu uname
                char skill2[30];
                for (k=1; k <= CKata.Length; k++){
                    skill2[k-1] = CKata.TabKata[k];
                }
                insertVSkill(pS2, *skill2);
                ADVKATA2();
            }
        }
        else if (i == 3){
            for (j=1; j <= jmlskill; j++){ // loop sebanyak jml skill di satu uname
                char skill3[30];
                for (k=1; k <= CKata.Length; k++){
                    skill3[k-1] = CKata.TabKata[k];
                }
                insertVSkill(pS3, *skill3);
                ADVKATA2();
            }
        }
        else if (i == 4){
            for (j=1; j <= jmlskill; j++){ // loop sebanyak jml skill di satu uname
                char skill4[30];
                for (k=1; k <= CKata.Length; k++){
                    skill4[k-1] = CKata.TabKata[k];
                }
                insertVSkill(pS4, *skill4);
                ADVKATA2();
            }
        }
    }
}