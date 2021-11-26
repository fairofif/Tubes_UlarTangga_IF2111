#include "console.h"

int main () {
    /*********** PREPARATION **********/

    /* Declare variable player */
        /* array of player information */
    pUserName pU;
    pIsTeleported pT;
        /* array of Buff Player Condition */
    pIsImune pI;
    pPosition pP;
    pIsCermin pC;
    pIsSenterBesar pSB;
    pIsSenterKecil pSK;
        /* linked list Skill */
    Skill pS1, pS2, pS3, pS4;

    /* Declare variable map */
    Map CurrentMap;

    /* Declare main variable */
    boolean stopProgram;
    boolean stopGame;
    boolean nextPlayer;
    int banyakPemain;
    int roll;
    int idxCurrentPlayer;
    int idxPKenaSkill;
    char command[20];
    char skname[30];
    char getSkill[30];
    char uname[30];
    int round;
    int nSkill;
    int pilihanskill;
    int tempPos;
    int skillDelete;
    


/* CATATAN BUG 
1. kalo HELP di awal, nanti dia bakal loop ke while line +-122.
2. kalo ROLL masih error.

*/



    /* loop program */
    stopProgram = FALSE;
    while (!stopProgram) {
        /* Prosedur UI Main Menu */
        welcome();
        /* input command */
        printf("Masukkan Command: ");
        strcpy(command, "");
        scanf("%s", command);

        /* Kalo commandnya HELP */
        if (strcmp(command, "HELP") == 0) {
            /* Tunjukin command2 yang ada di Main Menu */
            help();
        }
        /* Kalo new game */
        else if (strcmp(command, "NEWGAME") == 0) {
            /* Input file konfigurasi map yang mau dipake */
            inputConfig(&CurrentMap);
            printConfig(&CurrentMap);
            start();
            
            /* masukinn jumlah pemain & username pemain2nya */
            printf("Masukkan jumlah pemain: ");
            scanf("%d", &banyakPemain);
            preparationSkillList(&pS1,&pS2,&pS3,&pS4, banyakPemain);
            createEmptyPlayerList(&pU);
            summonPlayer(&pU, &pT, &pP, &pI, &pC, &pSB, &pSK, banyakPemain);

            /* kasih skill pertama buat para pemain */
            for (int i = 1; i <= banyakPemain; i++) {
                strcpy(getSkill, "");
                randomSkillGenerator(getSkill);
                if (i == 1) {
                    insertVSkill(&pS1, getSkill);
                }
                else if (i == 2) {
                    insertVSkill(&pS2, getSkill);
                }
                else if (i == 3) {
                    insertVSkill(&pS3, getSkill);
                }
                else if (i == 4) {
                    insertVSkill(&pS4, getSkill);
                }
            }

            /* set idxPlayer ke 1 */
            idxCurrentPlayer = 1;
            round = 1;
        }

        /* Kalo Exit */
        else if (strcmp(command, "EXIT") == 0) {
            /* stopProgram jadi TRUE */
            stopProgram = TRUE;
        }

        /* Kalo load game */
        else if (strcmp(command, "LOAD") == 0) {

            /* Load player data ke variable2 player */

            /* Load map data ke variable2 map */

            /* Load jumlah pemain dari Neff */

            /* Load idxCurrentPlayer terakhir */
        }
        
        
        stopGame = FALSE;
        while ((!stopGame) && (!stopProgram)) {
            nextPlayer = FALSE;
            
            /* Prosedur UI In Game */

            /* input command */
            printf("Masukkan Command: ");
            strcpy(command, "");
            scanf("%s", command);

            /* Kalo commandnya HELP */
            if (strcmp(command, "HELP") == 0) {
                help();
                /* Tunjukin command2 yang ada di In Game */

            }
            
            /* Kalo commandnya SKILL */
            else if (strcmp(command, "SKILL") == 0) {
                /* Keluarin SKILL LIST idxCurrentPlayer */
                printf("List Skill player %s: \n", pU.uname[idxCurrentPlayer]);
                printSkill(pS1, pS2, pS3, pS4, idxCurrentPlayer, &nSkill);

                /* input (int) SKILL yang mau dipake (kalo punya SKILL) */
                if (nSkill >= 1) {
                    printf("Ingin menggunakan skill No: ");
                    scanf("%d", &pilihanskill);
            
                    /* salin nama skill yang dipake ke variable */
                    strcpy(skname, "");
                    copySkillName(pS1, pS2, pS3, pS4, idxCurrentPlayer, pilihanskill, skname);

                    /* Kalo SKILL == "Pintu Ga Ke Mana Mana" */
                    if (strcmp(skname, "Pintu Ga Ke Mana Mana") == 0) {
                        /* CEK DULU UDAH ADA EFEK BUFFNYA BELOM */
                        if (pI.isImun[idxCurrentPlayer]) {
                            printf("Anda masih memiliki efek Imune, tidak bisa menggunakan Skill ini.\n");
                        }
                        else {
                            /* Perubahan kondisi di player */
                            pI.isImun[idxCurrentPlayer] = TRUE;
                            printf("Skill diaktifkan, Anda sekarang Memiliki efek Imune Teleport.\n");
                            deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);
                        }
                    }
                    /* Kalo SKILL == "Mesin Waktu" */
                    else if (strcmp(skname, "Mesin Waktu") == 0) {
                        /* Masukin username yang mau dimundurin */
                        printf("Masukkan username pemain untuk dimundurin: ");
                        strcpy(uname, "");
                        scanf("%s", uname);
                        idxPKenaSkill = getIdxOfPlayer(pU, uname);
                        
                        /* roll dadu dulu */
                        roll = rollDice(MAP_MAXROLL(CurrentMap));
                        roll = roll * (-1);

                        /* Perubahan kondisi player yang dimundurin */
                        movePlayer(roll, idxPKenaSkill, &CurrentMap, &pP);

                        /* Perubahan kondisi di player */
                        deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);

                        /* Perbuahan turn */
                        nextPlayer = TRUE;

                    }
                    /* Kalo SKILL == "Baling Baling Jambu" */
                    else if (strcmp(skname, "Baling Baling Jambu") == 0) {
                        /* Masukin username yang mau dimajuin */
                        printf("Masukkan username pemain untuk dimajuin: ");
                        strcpy(uname, "");
                        scanf("%s", uname);
                        idxPKenaSkill = getIdxOfPlayer(pU, uname);

                        /* roll dulu gan */
                        roll = rollDice(MAP_MAXROLL(CurrentMap));

                        /* Perubahan kondisi player yang dimajuin */
                        // movePlayer(roll, idxPKenaSkill, &CurrentMap, pP); HARUSNYA FORCE MOVE
                        
                        /* Perubahan kondisi di player */
                        deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);

                        /* Perbuahan turn */
                        nextPlayer = TRUE;
                    }
                    /* Kalo SKILL == "Cermin Pengganda" */
                    else if (strcmp(skname, "Cermin Pengganda") == 0) {
                        /* CEK DULU UDAH ADA EFEK BUFFNYA BELOM */
                        if (pC.isCermin[idxCurrentPlayer]) {
                            printf("Anda sudah menggunakan Cermin Pengganda di giliran ini, tidak bisa menggunakan Skill ini.\n");
                        }
                        else {
                            deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);
                            if (banyaknyaSkill(pS1, pS2, pS3, pS4, idxCurrentPlayer) > 8) {
                                while (banyaknyaSkill(pS1, pS2, pS3, pS4, idxCurrentPlayer) > 8) {
                                    printf("Skill maksimal 8 untuk menggunakan skill ini, harap hapus skill.\n");
                                    printSkill(pS1, pS2, pS3, pS4, idxCurrentPlayer, &nSkill);
                                    printf("Masukan nomor Skill yang ingin di hapus: ");
                                    scanf("%d", &skillDelete);
                                    deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, skillDelete);
                                }
                            } 
                            
                            /* Perubahan kondisi di player */
                            for (int i = 1; i <= 2 ; i++) {
                                strcpy(getSkill, "");
                                randomSkillGenerator(getSkill);
                                if (idxCurrentPlayer == 1) {
                                    insertVSkill(&pS1, getSkill);
                                }
                                else if (idxCurrentPlayer == 2) {
                                    insertVSkill(&pS2, getSkill);
                                }
                                else if (idxCurrentPlayer == 3) {
                                    insertVSkill(&pS3, getSkill);
                                }
                                else if (idxCurrentPlayer == 4) {
                                    insertVSkill(&pS4, getSkill);
                                }
                                printf("Skill %s sudah ditambahkan!\n", getSkill);
                            }
                            pC.isCermin[idxCurrentPlayer] = TRUE;
                        }
                    }    
                    /* Kalo SKILL == "Senter Pembesar Hoki" */
                    else if (strcmp(skname, "Senter Pembesar Hoki") == 0) {
                        /* CEK DULU UDAH ADA EFEK BUFFNYA BELOM */
                        if ((pSB.isSenterBesar[idxCurrentPlayer]) || (pSK.isSenterKecil[idxCurrentPlayer])) {
                            printf("Anda masih memiliki efek Senter Besar/Kecil, tidak bisa menggunakan Skill ini.\n");
                        }
                        else {
                            /* Perubahan kondisi di player */
                            pSB.isSenterBesar[idxCurrentPlayer] = TRUE;
                            deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);
                        }
                    } 
                    /* Kalo SKILL == "Senter Pengecil Hoki" */
                    else if (strcmp(skname, "Senter Pengecil Hoki") == 0) {
                        /* CEK DULU UDAH ADA EFEK BUFFNYA BELOM */
                        if ((pSB.isSenterBesar[idxCurrentPlayer]) || (pSK.isSenterKecil[idxCurrentPlayer])) {
                            printf("Anda masih memiliki efek Senter Besar/Kecil, tidak bisa menggunakan Skill ini.\n");
                        }
                        else {
                            /* Perubahan kondisi di player */
                            pSK.isSenterKecil[idxCurrentPlayer] = TRUE;
                            deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);
                        }
                    }
                    /* Kalo SKILL == "Mesin Penukar Posisi" */
                    else if (strcmp(skname, "Mesin Penukar Posisi") == 0) {
                        /* Masukin username yang mau dimajuin */
                        printf("Masukkan username pemain untuk ditukar posisi: ");
                        strcpy(uname, "");
                        scanf("%s", uname);
                        idxPKenaSkill = getIdxOfPlayer(pU, uname);

                        /* Perubahan kondisi player yang ditukar posisi */
                        tempPos = pP.pos[idxPKenaSkill];
                        // movePlayer((pP.pos[idxCurrentPlayer] - pP.pos[idxPKenaSkill]), idxPKenaSkill, &CurrentMap, pP); HARUSNYA FORCEMOVE
                        
                        /* Perubahan kondisi di player */
                        // movePlayer((tempPos - pP.pos[idxCurrentPlayer]), idxCurrentPlayer, &CurrentMap, pP); HARUSNYA FORCEMOVE
                        deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);

                        /* Perbuahan turn */
                        nextPlayer = TRUE;

                    }
                    /* Kalo SKILL == "Teknologi Gagal" */
                        /* NOTHING HAPPEN */
                }
                else {
                    printf("Anda tidak memiliki Skill apa pun untuk digunakan.\n");
                }
            }       
            

            /* Kalo Commandnya MAP */
            else if (strcmp(command, "MAP") == 0) {
              showMap(&pP, &pU, idxCurrentPlayer, &CurrentMap);
                // showMap(array of char username, idx posisi player);

            }

            /* Kalo Commandnya BUFF */
            else if (strcmp(command, "BUFF") == 0) {
            
            }
            /* Kalo Commandnya INSPECT */
            else if (strcmp(command, "INSPECT") == 0) {
                inspectMap(&CurrentMap);
            }
            /* Kalo Commandnya ROLL */
            else if (strcmp(command, "ROLL") == 0) {
                /*  yang ini dicek dulu Lagi ada efek Buff yang
                    ngaruh ke roll apa enggak.
                    pSB.isSenterBesar[idxCurrentPlayer]
                    pSK.isSenterKecil[idxCurrentPlayer]
                    kalo salah satunya aktif ntar ngaruh ke rollnya
                */
                printf("MAXROLLNYA %d\n", MAP_MAXROLL(CurrentMap));
                roll = rollDice(MAP_MAXROLL(CurrentMap));
                movePlayer(roll, idxCurrentPlayer, &CurrentMap, &pP);
            }
            /* Kalo Commandnya SAVE */
            else if (strcmp(command, "SAVE") == 0) {
                /* Update semua player txt */

                /* Update semua map txt */
            }
            /* Kalo Commandnya ENDTURN */
            else if (strcmp(command, "ENDTURN") == 0) {
                nextPlayer = TRUE;
            }
            /* Kalo Commandnya UNDO */
            else if (strcmp(command, "UNDO") == 0) {
                /* ini kita yang meninggal sebagai developer */

            }
            /* ini buat gantian giliran player */
            if (nextPlayer) {
                pC.isCermin[idxCurrentPlayer] = FALSE;
                if (idxCurrentPlayer == banyakPemain) {
                    idxCurrentPlayer = 1;
                    round++;
                }
                else {
                    idxCurrentPlayer++;
                }
            }

        }
    }
}