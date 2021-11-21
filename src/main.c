#include "console.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    /*********** PREPARATION **********/

    /* Declare variable player */
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

    /* Declare variable map */
    Map CurrentMap;

    /* Declare main variable */
    boolean stopProgram;
    boolean stopGame;
    boolean nextPlayer;
    int banyakPemain;
    int roll;
    int idxCurrentPlayer;
    char command[20];
    char *getSkill;



    /* loop program */
    stopProgram = FALSE;
    while (!stopProgram) {
        /* Prosedur UI Main Menu */
        welcome();
            
        /* input command */
        strcpy(command, "");
        scanf("%s", &command);

        /* Kalo commandnya HELP */
        if (strcmp(command, "HELP") == 0) {
            /* Tunjukin command2 yang ada di Main Menu */

        }
        /* Kalo new game */
        else if (strcmp(command, "NEWGAME") == 0) {
            /* Input file konfigurasi map yang mau dipake */
            inputConfig();
            
            /* masukinn jumlah pemain & username pemain2nya */
            scanf("%d", &banyakPemain);
            preparationSkillList(&pS1,&pS2,&pS3,&pS4, banyakPemain);
            createEmptyPlayerList(&pU);
            summonPlayer(&pU, &pT, &pP, &pI, &pC, &pSB, &pSK, &pMW, &pB, &pPen, &pTG, banyakPemain);

            /* kasih skill pertama buat para pemain */
            for (int i = 1; i <= banyakPemain; i++) {
                strcpy(getSkill, "");
                randomSkillGenerator(&getSkill);
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
        start();
        while ((!stopGame) && (!stopProgram)) {
            nextPlayer = FALSE;
            
            /* Prosedur UI In Game */

            /* input command */
            strcpy(command, "");
            scanf("%s", &command);

            /* Kalo commandnya HELP */
            if (strcmp(command, "HELP") == 0) {
                help();
                /* Tunjukin command2 yang ada di In Game */

            }

            else if (strcmp(command, "SKILL") == 0) {
            /* Kalo commandnya SKILL */
                /* Keluarin SKILL LIST idxCurrentPlayer */

                /* input (int) SKILL yang mau dipake (kalo punya SKILL) */

                /* salin nama skill yang dipake ke variable */

                /* Kalo Masukin SKILL */
                    /* Kalo SKILL == "Pintu Ga Ke Mana Mana" */
                        /* Perubahan kondisi di player */

                        /* Perbuahan kondisi di Map */
                    
                    /* Kalo SKILL == "Mesin Waktu" */
                        /* Masukin username yang mau dimundurin */

                        /* Perubahan kondisi player yang dimundurin */
                        
                        /* Perubahan kondisi di player */

                        /* Perbuahan kondisi di Map */

                    /* Kalo SKILL == "Baling Baling Jambu" */
                        /* Masukin username yang mau dimajuin */

                        /* Perubahan kondisi player yang dimajuin */
                        
                        /* Perubahan kondisi di player */

                        /* Perbuahan kondisi di Map */
                    
                    /* Kalo SKILL == "Cermin Pengganda" */
                        /* Perubahan kondisi di player */

                    /* Kalo SKILL == "Senter Pembesar Hoki" */
                        /* ROLL dadu pake efek senter pembesar hoki */
                        
                        /* Perubahan kondisi di player */

                        /* Perbuahan kondisi di Map */

                    /* Kalo SKILL == "Senter Pengecil Hoki" */
                        /* ROLL dadu pake efek senter pengecil hoki */
                        
                        /* Perubahan kondisi di player */

                        /* Perbuahan kondisi di Map */

                    /* Kalo SKILL == "Mesin Penukar Posisi" */
                        /* Masukin username yang mau dituker sama current player */
                        
                        /* Perubahan kondisi di player yang dituker */

                        /* Perubahan kondisi player current */

                        /* Perbuahan kondisi di Map */

                    /* Kalo SKILL == "Teknologi Gagal" */
                        /* NOTHING HAPPEN */
            }       
            

            /* Kalo Commandnya MAP */
            else if (strcmp(command, "MAP") == 0) {
              showMap(pU.uname[idxCurrentPlayer], pP.pos[idxCurrentPlayer]);
                // showMap(array of char username, idx posisi player);

            }

            /* Kalo Commandnya BUFF */
            else if (strcmp(command, "BUFF") == 0) {
            
            }
            /* Kalo Commandnya INSPECT */
            else if (strcmp(command, "INSPECT") == 0) {

            }
            /* Kalo Commandnya ROLL */
            else if (strcmp(command, "ROLL") == 0) {
                roll = rollDice(MAP_MAXROLL(CurrentMap));
                movePlayer(roll, idxCurrentPlayer, CurrentMap);
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
                if (idxCurrentPlayer == banyakPemain) {
                    idxCurrentPlayer = 1;
                }
                else {
                    idxCurrentPlayer++;
                }
            }

        }


    }
}