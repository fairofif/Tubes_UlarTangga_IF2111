#include <stdio.h>
#include "save.h"

void shortenSkillName(char skillName[]){
    if (strcmp(skillName, "Pintu Ga Ke Mana Mana") == 0){
        strcpy(skillName, "PintuGaKeManaMana");
    }
    else if (strcmp(skillName, "Mesin Waktu") == 0){
        strcpy(skillName, "MesinWaktu");
    }
    else if (strcmp(skillName, "Baling Baling Jambu") == 0){
        strcpy(skillName, "BalingBalingJambu");
    }
    else if (strcmp(skillName, "Cermin Pengganda") == 0){
        strcpy(skillName, "CerminPengganda");
    }
    else if (strcmp(skillName, "Senter Pembesar Hoki") == 0){
        strcpy(skillName, "SenterPembesarHoki");
    }
    else if (strcmp(skillName, "Senter Pengecil Hoki") == 0){
        strcpy(skillName, "SenterPengecilHoki");
    }
    else if (strcmp(skillName, "Mesin Penukar Posisi") == 0){
        strcpy(skillName, "MesinPenukarPosisi");
    }
    else if (strcmp(skillName, "Teknologi Gagal") == 0){
        strcpy(skillName, "TeknologiGagal");
    }
}

void Save(int n, int round, char mapname[], pUserName pU, pIsTeleported pT, pPosition pP, pIsImune pI, pIsCermin pC,
pIsSenterBesar pSB, pIsSenterKecil pSK, Skill pS1, Skill pS2, Skill pS3, Skill pS4){
// KAMUS
    int i;
    char filename[100];
    char skname[30];

// ALGORITMA
    printf("Masukkan nama save file yang ingin dibuat: ");
    scanf("%s", filename);

    FILE *pfile = fopen(filename, "wt");


    printf("coba nama mapname %s\n", mapname);
    fprintf(pfile, "%s\n", mapname);

    fprintf(pfile, "%d\n", n);

    fprintf(pfile, "%d\n", round);

    // Data status player
    for (i=1; i<=n; i++){
        fprintf(pfile, "%s\n", pU.uname[i]);
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
                strcpy(skname, SKILLNAME(P));
                shortenSkillName(skname);
                fprintf(pfile, "%s\n", skname);
                P = NEXTSKILL(P);
            }
        }
        else if (i == 2){
            address P = ADDR_HEADSKILL(pS2);
            while (P != 0){
                strcpy(skname, SKILLNAME(P));
                shortenSkillName(skname);
                fprintf(pfile, "%s\n", skname);
                P = NEXTSKILL(P);
            }
        }
        else if (i == 3){
            address P = ADDR_HEADSKILL(pS3);
            while (P != 0){
                strcpy(skname, SKILLNAME(P));
                shortenSkillName(skname);
                fprintf(pfile, "%s\n", skname);
                P = NEXTSKILL(P);
            }
        }
        else if (i == 4){
            address P = ADDR_HEADSKILL(pS4);
            while (P != 0){
                strcpy(skname, SKILLNAME(P));
                shortenSkillName(skname);
                fprintf(pfile, "%s\n", skname);
                P = NEXTSKILL(P);
            }
        }
    }
    fprintf(pfile, "!");
    fclose(pfile);
    printf("Game berhasil di save yuhu!\n");
    getchar();
}