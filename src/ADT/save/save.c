#include <stdio.h>
#include "save.h"

void Save(int n, pUserName pU, pIsTeleported pT, pPosition pP, pIsImune pI, pIsCermin pC,
pIsSenterBesar pSB, pIsSenterKecil pSK, Skill pS1, Skill pS2, Skill pS3, Skill pS4){
// KAMUS
    int i;
    char filename[100];

// ALGORITMA
    printf("Masukkan nama save file yang ingin dibuat: ");
    scanf("%s", filename);

    FILE *pfile = fopen(filename, "wt");

    // Save file map 
    // printf("%s\n", mapfilename);
    // fprintf(pfile, "%s\n", mapfilename);

    // Data status player
    for (i=1; i<=n; i++){
        fprintf(pfile, "%d\n", getPositionOfPlayer(pP, i));
        fprintf(pfile, "%d\n", getTeleportedConditionOfPlayer(pT, i));
        fprintf(pfile, "%d\n", getImmunityConditionOfPlayer(pI, i));
        fprintf(pfile, "%d\n", getCerminConditionOfPlayer(pC, i));
        fprintf(pfile, "%d\n", getSenterBesarConditionOfPlayer (pSB, i));
        fprintf(pfile, "%d\n", getSenterKecilConditionOfPlayer(pSK, i));
    }

    // Data skill yang dimiliki player
    for (i=1; i<=n; i++){
        fprintf(pfile, "%d\n", banyaknyaSkill(pS1, pS2, pS3, pS4, i));
        if (i == 1){
            address P = ADDR_HEADSKILL(pS1);
            while (P != 0){
                fprintf(pfile, "%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
            
        }
        else if (i == 2){
            address P = ADDR_HEADSKILL(pS2);
            while (P != 0){
                fprintf(pfile, "%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        else if (i == 3){
            address P = ADDR_HEADSKILL(pS3);
            while (P != 0){
                fprintf(pfile, "%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        else if (i == 4){
            address P = ADDR_HEADSKILL(pS4);
            while (P != 0){
                fprintf(pfile, "%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
    }
    
    fclose(pfile);
    printf("Game berhasil di save yuhu!\n");
    getchar();
}