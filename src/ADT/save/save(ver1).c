/*  Implementasi save.h untuk Save1
    Akses elemen pakai stack 
    Data Map belum di masukkan */

#include <stdio.h>
#include "save.h"


void Save1(int n){
// KAMUS
    int i;
    char filename[254] = "savefile/";

    pUserName pU;
    pIsImune pI;
    pIsTeleported pT;
    pPosition pP;
    pIsCermin pC;
    pIsSenterBesar pSB;
    pIsSenterKecil pSK;
    pIsMesinWaktu pMW;
    pIsBalingBaling pB;
    pIsPenukar pPen;
    pIsTeknologiGagal pTG;
    Skill pS1, pS2, pS3, pS4;


// ALGORITMA

    printf("Masukkan nama save file yang pengen dibuat: ");
    scanf("%s", filename + 9);

    FILE *pfile = fopen(filename, "w");

    // Data status player ver 2
    for (i=1; i<=n; i++){
        fprintf(pfile, "%s\n", pU.uname[i]);
        fprintf(pfile, "%d\n", getPositionOfPlayer(pP, i));
        fprintf(pfile, "%s\n", getTeleportedConditionOfPlayer(pT, i));
        fprintf(pfile, "%s\n", getImmunityConditionOfPlayer(pI, i));
        fprintf(pfile, "%s\n", getCerminConditionOfPlayer(pC, i));
        fprintf(pfile, "%s\n", getSenterBesarConditionOfPlayer (pSB, i));
        fprintf(pfile, "%s\n", getSenterKecilConditionOfPlayer(pSK, i));
        fprintf(pfile, "%s\n", getMesinWaktuConditionOfPlayer(pMW, i));
        fprintf(pfile, "%s\n", getBalingBalingConditionOfPlayer(pB, i));
        fprintf(pfile, "%s\n", getPenukarConditionOfPlayer(pPen, i));
        fprintf(pfile, "%s\n", getTeknologiGagalConditionOfPlayer(pTG, i));
    }

    // Data skill yang dimiliki player
    for (i=1; i<=n; i++){
        if (i == 1){
            address P = ADDR_HEADSKILL(pS1);
            while (P != Nil){
                fprintf(pfile, "%s", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
            
        }
        else if (i == 2){
            address P = ADDR_HEADSKILL(pS2);
            while (P != Nil){
                fprintf(pfile, "%s", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        else if (i == 3){
            address P = ADDR_HEADSKILL(pS3);
            while (P != Nil){
                fprintf(pfile, "%s", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        else if (i == 4){
            address P = ADDR_HEADSKILL(pS4);
            while (P != Nil){
                fprintf(pfile, "%s", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
    }

}