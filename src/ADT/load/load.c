#include <sys/stat.h>
#include "load.h"

boolean IsFileExists(char *filename){
    struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)
        return TRUE;
    else  
        return FALSE;
}

void unshortenSkillName(char skillName[]){
    if (strcmp(skillName, "PintuGaKeManaMana") == 0){
        strcpy(skillName, "Pintu Ga Ke Mana Mana");
    }
    else if (strcmp(skillName, "MesinWaktu") == 0){
        strcpy(skillName, "Mesin Waktu");
    }
    else if (strcmp(skillName, "BalingBalingJambu") == 0){
        strcpy(skillName, "Baling Baling Jambu");
    }
    else if (strcmp(skillName, "CerminPengganda") == 0){
        strcpy(skillName, "Cermin Pengganda");
    }
    else if (strcmp(skillName, "SenterPembesarHoki") == 0){
        strcpy(skillName, "Senter Pembesar Hoki");
    }
    else if (strcmp(skillName, "SenterPengecilHoki") == 0){
        strcpy(skillName, "Senter Pengecil Hoki");
    }
    else if (strcmp(skillName, "MesinPenukarPosisi") == 0){
        strcpy(skillName, "Mesin Penukar Posisi");
    }
    else if (strcmp(skillName, "TeknologiGagal") == 0){
        strcpy(skillName, "Teknologi Gagal");
    }
}

void Load(int *banyakPemain, char *configmap, int *round, pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC,
pIsSenterBesar *pSB, pIsSenterKecil *pSK, Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4){
// KAMUS
    int i, jmlskill, j, k; 
    char filename[100];
    char configname[20];
    char skname[30];
    char uname[30];
    char skill1[30];
    char skill2[30];
    char skill3[30];
    char skill4[30];

// ALGORITMA

    createEmptyPlayerSkillsList(pS1);
    createEmptyPlayerSkillsList(pS2);
    createEmptyPlayerSkillsList(pS3);
    createEmptyPlayerSkillsList(pS4);

    boolean valid = FALSE;
    while(!valid){
        printf("Masukkan file name yang ingin diload: ");
        scanf("%s", filename);
        if(IsFileExists(filename)){
            printf("Load file berhasil, selamat bermain!\n");
            valid = TRUE;
        }
        else {
            printf("ERROR!! File tidak ditemukan.\n");
        }
    }

    STARTKATA2(filename);

    // NAMA MAP
    for (k=1; k <= CKata.Length; k++){
        configname[k-1] = CKata.TabKata[k];
    }
    strcpy(configmap, configname);
    printf("file configmap >> %s\n", configmap);
    ADVKATA2();

    // Data game general
    *banyakPemain = KataToInt(CKata);
    ADVKATA2();
    *round = KataToInt(CKata);
    ADVKATA2();

    // Load kondisi player
    for (i=1; i<=*banyakPemain; i++){
        
        for (k=1; k <= CKata.Length; k++){
            uname[k-1] = CKata.TabKata[k];
        }
        strcpy((*pU).uname[i], uname); 
        ADVKATA2();

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
    for (i=1; i<=*banyakPemain; i++){
        jmlskill = KataToInt(CKata); ADVKATA2();

        if (i == 1){
            for (j=1; j <= jmlskill; j++){ // loop sebanyak jml skill di satu uname
                for (k=1; k <= CKata.Length; k++){
                    skill1[k-1] = CKata.TabKata[k];
                }
                strcpy(skname, skill1);
                unshortenSkillName(skname);
                insertVSkill(pS1, skname);
                ADVKATA2();
            }
            address P = ADDR_HEADSKILL(*pS1);
            while (P != 0){
                printf("%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }

        else if (i == 2){
            for (j=1; j <= jmlskill; j++){ // loop sebanyak jml skill di satu uname
                for (k=1; k <= CKata.Length; k++){
                    skill2[k-1] = CKata.TabKata[k];
                }
                strcpy(skname, skill2);
                unshortenSkillName(skname);
                insertVSkill(pS2, skname);
                ADVKATA2();
            }
            address P = ADDR_HEADSKILL(*pS2);
            while (P != 0){
                printf("%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }

        else if (i == 3){
            for (j=1; j <= jmlskill; j++){ // loop sebanyak jml skill di satu uname
                for (k=1; k <= CKata.Length; k++){
                    skill3[k-1] = CKata.TabKata[k];
                }
                strcpy(skname, skill3);
                unshortenSkillName(skname);
                insertVSkill(pS3, skname);
                ADVKATA2();
            }
            address P = ADDR_HEADSKILL(*pS3);
            while (P != 0){
                printf("%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
        
        else if (i == 4){
            for (j=1; j <= jmlskill; j++){ // loop sebanyak jml skill di satu uname
                for (k=1; k <= CKata.Length; k++){
                    skill4[k-1] = CKata.TabKata[k];
                }
                strcpy(skname, skill4);
                unshortenSkillName(skname);
                insertVSkill(pS4, skname);
                ADVKATA2();
            }
            address P = ADDR_HEADSKILL(*pS4);
            while (P != 0){
                printf("%s\n", SKILLNAME(P));
                P = NEXTSKILL(P);
            }
        }
    }
}