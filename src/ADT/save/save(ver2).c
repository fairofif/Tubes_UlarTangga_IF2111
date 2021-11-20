/*  Implementasi save.h untuk Save2
    Akses elemen pakai fungsi yang sudah ada di player.c 
    Data Map belum di masukkan */

#include <stdio.h>
#include "save.h"


void Save1(SEltype State, int n){
// KAMUS
    int i;
    char filename[254] = "savefile/";

    Skill pS1, pS2, pS3, pS4;


// ALGORITMA

    printf("Masukkan nama save file yang pengen dibuat: ");
    scanf("%s", filename + 9);

    FILE *pfile = fopen(filename, "w");

    // Data kondisi (status, posisi, username) player
    for (i=1; i<=n; i++){
        if (i == 1){ // Simpan kondisi (status, posisi, username) player 1
            fprintf(pfile, "%s\n", Pos(P1Info(State)).pos[i]);
            fprintf(pfile, "%s\n", teleCond(PCond(P1Info(State))).isTele[i]);
            fprintf(pfile, "%d\n", imunCond(PCond(P1Info(State))).isImun[i]);
            fprintf(pfile, "%s\n", cerminCond(PCond(P1Info(State))).isCermin[i]);
            fprintf(pfile, "%s\n", sbesarCond(PCond(P1Info(State))).isSenterBesar[i]);
            fprintf(pfile, "%s\n", skecilCond(PCond(P1Info(State))).isSenterKecil[i]);
            fprintf(pfile, "%s\n", mwaktuCond(PCond(P1Info(State))).isMesin[i]);
            fprintf(pfile, "%s\n", balingCond(PCond(P1Info(State))).isBaling[i]);
            fprintf(pfile, "%s\n", penukarCond(PCond(P1Info(State))).isTukar[i]);
            fprintf(pfile, "%s\n", tekgagalCond(PCond(P1Info(State))).isTek[i]);
        } 
        else if (i == 2){ // Simpan kondisi/kondisi (status, posisi, username) player 2
            fprintf(pfile, "%s\n", teleCond(PCond(P2Info(State))).isTele[i]);
            fprintf(pfile, "%d\n", imunCond(PCond(P2Info(State))).isImun[i]);
            fprintf(pfile, "%s\n", cerminCond(PCond(P2Info(State))).isCermin[i]);
            fprintf(pfile, "%s\n", sbesarCond(PCond(P2Info(State))).isSenterBesar[i]);
            fprintf(pfile, "%s\n", skecilCond(PCond(P2Info(State))).isSenterKecil[i]);
            fprintf(pfile, "%s\n", mwaktuCond(PCond(P2Info(State))).isMesin[i]);
            fprintf(pfile, "%s\n", balingCond(PCond(P2Info(State))).isBaling[i]);
            fprintf(pfile, "%s\n", penukarCond(PCond(P2Info(State))).isTukar[i]);
            fprintf(pfile, "%s\n", tekgagalCond(PCond(P2Info(State))).isTek[i]);
        }   
        else if (i == 3){ // Simpan kondisi/kondisi (status, posisi, username) player 3
            fprintf(pfile, "%s\n", teleCond(PCond(P3Info(State))).isTele[i]);
            fprintf(pfile, "%d\n", imunCond(PCond(P3Info(State))).isImun[i]);
            fprintf(pfile, "%s\n", cerminCond(PCond(P3Info(State))).isCermin[i]);
            fprintf(pfile, "%s\n", sbesarCond(PCond(P3Info(State))).isSenterBesar[i]);
            fprintf(pfile, "%s\n", skecilCond(PCond(P3Info(State))).isSenterKecil[i]);
            fprintf(pfile, "%s\n", mwaktuCond(PCond(P3Info(State))).isMesin[i]);
            fprintf(pfile, "%s\n", balingCond(PCond(P3Info(State))).isBaling[i]);
            fprintf(pfile, "%s\n", penukarCond(PCond(P3Info(State))).isTukar[i]);
            fprintf(pfile, "%s\n", tekgagalCond(PCond(P3Info(State))).isTek[i]);
        }
        else if (i == 4){ // Simpan kondisi/kondisi (status, posisi, username) player 4
            fprintf(pfile, "%s\n", teleCond(PCond(P4Info(State))).isTele[i]);
            fprintf(pfile, "%d\n", imunCond(PCond(P4Info(State))).isImun[i]);
            fprintf(pfile, "%s\n", cerminCond(PCond(P4Info(State))).isCermin[i]);
            fprintf(pfile, "%s\n", sbesarCond(PCond(P4Info(State))).isSenterBesar[i]);
            fprintf(pfile, "%s\n", skecilCond(PCond(P4Info(State))).isSenterKecil[i]);
            fprintf(pfile, "%s\n", mwaktuCond(PCond(P4Info(State))).isMesin[i]);
            fprintf(pfile, "%s\n", balingCond(PCond(P4Info(State))).isBaling[i]);
            fprintf(pfile, "%s\n", penukarCond(PCond(P4Info(State))).isTukar[i]);
            fprintf(pfile, "%s\n", tekgagalCond(PCond(P4Info(State))).isTek[i]);
        }
    }


    // Data skill yang dimiliki player
    for (i=1; i<=n; i++){
        if (i == 1){
            address P = ADDR_HEADSKILL(pS1);
            while (P != Nil){
                fprintf(pfile, "%s", LSkill(P1Info(State)));
                P = NEXTSKILL(P);
            }
            
        }
        else if (i == 2){
            address P = ADDR_HEADSKILL(pS2);
            while (P != Nil){
                fprintf(pfile, "%s", LSkill(P2Info(State)));
                P = NEXTSKILL(P);
            }
        }
        else if (i == 3){
            address P = ADDR_HEADSKILL(pS3);
            while (P != Nil){
                fprintf(pfile, "%s", LSkill(P3Info(State)));
                P = NEXTSKILL(P);
            }
        }
        else if (i == 4){
            address P = ADDR_HEADSKILL(pS4);
            while (P != Nil){
                fprintf(pfile, "%s", LSkill(P4Info(State)));
                P = NEXTSKILL(P);
            }
        }
    }

}