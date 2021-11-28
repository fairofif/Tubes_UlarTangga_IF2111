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

    // Declare variable round //
    Round R;

    /* Declare main variable */
    boolean stopProgram;
    boolean stopGame;
    boolean nextPlayer;
    boolean inputValid;
    boolean ableToRoll;
    boolean undoLagi;
    int banyakPemain;
    int roll;
    int idxCurrentPlayer;
    int idxPKenaSkill;
    char command[20];
    char skname[30];
    char getSkill[30];
    char uname[30];
    int prevPos;
    int round;
    int nSkill;
    int pilihanskill;
    int tempPos;
    int skillDelete;
    int currPos;
    int loopSkill;
    int buff;
    int x1;
    char mapname[20];
    char configmap[20];
    char hasilconfigmap[20];
    boolean adajuara;


    /* CATATAN BUG 
    1. kalo HELP di awal, nanti dia bakal loop ke while line +-122.
    2. kalo ROLL masih error.
    */



    /* loop program */
    stopGame = TRUE;
    stopProgram = FALSE;
    while (!stopProgram) {
        /* Prosedur UI Main Menu */
        welcome();

        /* input command */
        /* loop sampe input valid */
        inputValid = FALSE;
        while(!inputValid) {
            printf("\nMasukkan Command: ");
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
                adajuara = TRUE;
                inputConfig(&CurrentMap);
                for(int i = 0; i < 20; i++ ) {
                    mapname[i] = (*fileconfig)[i];
                }
                printConfig(&CurrentMap);
                start();

                /* masukinn jumlah pemain & username pemain2nya */
                while(banyakPemain < 2 || banyakPemain > 4) {
                    printf("Masukkan jumlah pemain: ");
                    scanf("%d", &banyakPemain);
                }
                
                preparationSkillList(&pS1,&pS2,&pS3,&pS4, banyakPemain);
                createEmptyPlayerList(&pU);
                summonPlayer(&pU, &pT, &pP, &pI, &pC, &pSB, &pSK, banyakPemain);

                
                /* set idxPlayer ke 1 */
                idxCurrentPlayer = 1;
                createEmptyRound(&R);
                round = 1;
                inputValid = TRUE;
                stopGame = FALSE;
                printf("\n||| ROUND %d  |||\n\n", round);

                /* kasih skill pertama buat pemain 1 */
                srand(time(0));
                if (banyaknyaSkill(pS1,pS2,pS3,pS4, idxCurrentPlayer) < 10) {
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
                    printf("Bonus Pre-Turn Round %d: ", round);
                    printf("%s berhasil ditambahkan ke %s\n", getSkill, pU.uname[idxCurrentPlayer]);
                }

                

                printf("Silahkan bermain %s!\n", pU.uname[idxCurrentPlayer]);
            }

            /* Kalo Exit */
            else if (strcmp(command, "EXIT") == 0) {
                /* stopProgram jadi TRUE */
                stopProgram = TRUE;
                inputValid = TRUE;
                adajuara = FALSE;
            }

            /* Kalo load game */
            else if (strcmp(command, "LOAD") == 0) {
                
                adajuara = TRUE;
                /* Load player data ke variable2 player */
                createEmptyRound(&R);
                Load(&banyakPemain, configmap, &round, &pU, &pT, &pP, &pI, &pC, &pSB, &pSK, &pS1, &pS2, &pS3, &pS4);
                
                /* Load map data ke variable2 map */
                loadConfig(&CurrentMap, configmap);
                for(int i = 0; i < 20; i++ ){
                    (*fileconfig)[i] = configmap[i];
                }
                printConfig(&CurrentMap);
            
                
                idxCurrentPlayer = 1;
                printf("||  round %d   ||\n, round");

                /* kasih skill pertama buat pemain 1 */
                srand(time(0));
                if (banyaknyaSkill(pS1,pS2,pS3,pS4, idxCurrentPlayer) < 10) {
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
                    printf("Bonus Pre-Turn Round %d: ", round);
                    printf("%s berhasil ditambahkan ke %s\n", getSkill, pU.uname[idxCurrentPlayer]);
                }

                printf("Silahkan bermain %s!\n", pU.uname[idxCurrentPlayer]);


                /* Load idxCurrentPlayer terakhir */
                inputValid = TRUE;
                stopGame = FALSE;
            }

            else {
                printf("ERROR!! masukkan input command yang benar\n<HELP/NEWGAME/EXIT/LOAD>\n");
            }
        }      
        
        ableToRoll = TRUE;
        while ((!stopGame) && (!stopProgram)) {
            nextPlayer = FALSE;
            
            /* Prosedur UI In Game */
            
            /* input command */
            printf("\nMasukkan Command: ");
            strcpy(command, "");
            scanf("%s", command);

            /* Kalo commandnya HELP */
            if (strcmp(command, "HELP") == 0) {
                help();
                /* Tunjukin command2 yang ada di In Game */
            }

            else if (strcmp(command, "EXIT") == 0) {
                stopProgram = TRUE;
                adajuara = FALSE;
            }
            
            /* Kalo commandnya SKILL */
            else if (strcmp(command, "SKILL") == 0) {
                /* Keluarin SKILL LIST idxCurrentPlayer */
                printf("List Skill player %s: \n", pU.uname[idxCurrentPlayer]);
                printSkill(pS1, pS2, pS3, pS4, idxCurrentPlayer, &nSkill);

                /* input (int) SKILL yang mau dipake (kalo punya SKILL) */
                if (nSkill >= 1) {
                    strcpy(command, "");
                    printf("\nJadi menggunakan SKILL? (Y/N): ");
                    scanf("%s", command);
                    while (strcmp(command, "Y") != 0 && strcmp(command, "N") != 0) {
                        printf("Input salah, masukan Y/N.\n");
                        strcpy(command, "");
                        printf("\nJadi menggunakan SKILL? (Y/N): ");
                        scanf("%s", command);
                    }

                    if (strcmp(command, "Y") == 0) {
                        printf("\nIngin menggunakan skill No: ");
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
                            printf("Daftar Pemain: \n");
                            for (int i = 1; i <= banyakPemain; i++) {
                                printf("%d. %s\n", i, pU.uname[i]);
                            }
                            printf("Masukkan username pemain untuk dimundurin: ");
                            strcpy(uname, "");
                            scanf("%s", uname);
                            while (strcmp(uname, pU.uname[idxCurrentPlayer])==0) {
                                printf("Hanya bisa memindahkan player lain.\nMasukkan username pemain untuk dimajuin: ");
                                strcpy(uname, "");
                                scanf("%s", uname);
                            }
                            idxPKenaSkill = getIdxOfPlayer(pU, uname);
                            
                            /* roll dadu dulu */
                            srand(time(0));
                            roll = rollDice(MAP_MAXROLL(CurrentMap));
                            roll = roll * (-1);

                            /* Perubahan kondisi player yang dimundurin */
                            forceMove(roll, idxPKenaSkill, &CurrentMap, &pP, &pI);
                            if (getPositionOfPlayer(pP, idxPKenaSkill) < 1) {
                                forceMove((1 - getPositionOfPlayer(pP,idxPKenaSkill)), idxPKenaSkill, &CurrentMap, &pP, &pI);
                            }


                            /* Perubahan kondisi di player */
                            deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);

                            /* Perbuahan turn */
                            nextPlayer = TRUE;

                        }
                        /* Kalo SKILL == "Baling Baling Jambu" */
                        else if (strcmp(skname, "Baling Baling Jambu") == 0) {
                            /* Masukin username yang mau dimajuin */
                            printf("Daftar Pemain: \n");
                            for (int i = 1; i <= banyakPemain; i++) {
                                printf("%d. %s\n", i, pU.uname[i]);
                            }
                            printf("Masukkan username pemain untuk dimajuin: ");
                            strcpy(uname, "");
                            scanf("%s", uname);
                            while (strcmp(uname, pU.uname[idxCurrentPlayer])==0) {
                                printf("Hanya bisa memindahkan player lain.\nMasukkan username pemain untuk dimajuin: ");
                                strcpy(uname, "");
                                scanf("%s", uname);
                            }
                            idxPKenaSkill = getIdxOfPlayer(pU, uname);
                     
                            /* roll dulu gan */
                            srand(time(0));
                            roll = rollDice(MAP_MAXROLL(CurrentMap));
                            x1 = getPositionOfPlayer(pP, idxPKenaSkill);

                            /* Perubahan kondisi player yang dimajuin */
                            forceMove(roll, idxPKenaSkill, &CurrentMap, &pP, &pI);
                            if (getPositionOfPlayer(pP, idxPKenaSkill) > MAP_LENGTH(CurrentMap)) {
                                pP.pos[idxPKenaSkill] = x1;
                                printf("Tidak bisa pindah, karena roll menghasilkan posisi > %d\n", MAP_LENGTH(CurrentMap));
                            }

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
                                        printf("\n");
                                        deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, skillDelete);
                                    }
                                } 
                                
                                /* Perubahan kondisi di player */
                                srand(time(0));
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
                            while (strcmp(uname, pU.uname[idxCurrentPlayer])==0) {
                                printf("Hanya bisa tukar tempat dengan player lain.\nMasukkan username pemain untuk dimajuin: ");
                                strcpy(uname, "");
                                scanf("%s", uname);
                            }
                            idxPKenaSkill = getIdxOfPlayer(pU, uname);

                            /* Perubahan kondisi player yang ditukar posisi */
                            tempPos = pP.pos[idxPKenaSkill];
                            forceMove((pP.pos[idxCurrentPlayer] - tempPos), idxPKenaSkill, &CurrentMap, &pP, &pI);
                            
                            /* Perubahan kondisi di player */
                            forceMove((tempPos - pP.pos[idxCurrentPlayer]), idxCurrentPlayer, &CurrentMap, &pP, &pI);

                            deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);

                            /* Perbuahan turn */
                            nextPlayer = TRUE;

                        }
                        /* Kalo SKILL == "Teknologi Gagal" */
                        else if (strcmp(skname, "Teknologi Gagal") == 0) {
                            /* NOTHING HAPPEN */
                            deleteSkill(&pS1, &pS2, &pS3, &pS4, idxCurrentPlayer, pilihanskill);
                        }
                    }
                    else {
                        printf("Anda tidak jadi menggunakan hak SKILL.\n");
                    }
                    
                }
                else {
                    printf("Anda tidak memiliki Skill apa pun untuk digunakan.\n");
                }
            }       
            

            /* Kalo Commandnya MAP */
            else if (strcmp(command, "MAP") == 0) {
              showMap(&pP, &pU, banyakPemain, &CurrentMap);
                // showMap(array of char username, idx posisi player);

            }
            
            
            /* Kalo Commandnya BUFF */
            else if (strcmp(command, "BUFF") == 0) {
                buff = 0;
                if (getImmunityConditionOfPlayer(pI, idxCurrentPlayer)) {
                    buff++;
                    printf("%d. Imunitas Teleport\n", buff);
                }
                if (getCerminConditionOfPlayer(pC, idxCurrentPlayer)) {
                    buff++;
                    printf("%d. Cermin Pengganda\n", buff);
                }
                if (getSenterBesarConditionOfPlayer(pSB, idxCurrentPlayer)) {
                    buff++;
                    printf("%d. Senter Pembesar Hoki\n", buff);
                }
                if (getSenterKecilConditionOfPlayer(pSK, idxCurrentPlayer)) {
                    buff++;
                    printf("%d. Senter Pengecil Hoki\n", buff);
                }
                if (buff == 0) {
                    printf("Anda tidak memiliki efek BUFF, aktifkan salah satu BUFF dengan menggunakan SKILL.\n");
                }
                
            }

            /* Kalo Commandnya INSPECT */
            else if (strcmp(command, "INSPECT") == 0) {
                inspectMap(&CurrentMap);
            }

            /* Kalo Commandnya ROLL */
            else if (strcmp(command, "ROLL") == 0) {
                prevPos = getPositionOfPlayer(pP, idxCurrentPlayer);
                if(ableToRoll) {
                    if (getSenterBesarConditionOfPlayer(pSB, idxCurrentPlayer)){
                        printf("Anda memiliki Buff Senter Besar, roll akan >= %d\n", MAP_MAXROLL(CurrentMap)/2);
                        srand(time(0));
                        roll = rollDice(MAP_MAXROLL(CurrentMap));
                        while (roll < (MAP_MAXROLL(CurrentMap)/2)) {
                            printf("Karena roll < %d, maka roll diulang otomatis...\n", MAP_MAXROLL(CurrentMap)/2);
                            roll = rollDice(MAP_MAXROLL(CurrentMap));
                        }
                        pSB.isSenterBesar[idxCurrentPlayer] = FALSE;
                    }
                    else if (getSenterKecilConditionOfPlayer(pSK, idxCurrentPlayer)){
                        printf("Anda memiliki Buff Senter Kecil, roll akan <= %d\n", MAP_MAXROLL(CurrentMap)/2);
                        srand(time(0));
                        roll = rollDice(MAP_MAXROLL(CurrentMap));
                        while (roll > (MAP_MAXROLL(CurrentMap)/2)) {
                            printf("Karena roll > %d, maka roll diulang otomatis...\n", MAP_MAXROLL(CurrentMap)/2);
                            roll = rollDice(MAP_MAXROLL(CurrentMap));
                        }
                        pSK.isSenterKecil[idxCurrentPlayer] = FALSE;
                    }
                    else {
                        srand(time(0));
                        roll = rollDice(MAP_MAXROLL(CurrentMap));
                    }
                    movePlayer(roll, idxCurrentPlayer, &CurrentMap, &pP);
                    if (prevPos != getPositionOfPlayer(pP, idxCurrentPlayer)) {
                        teleport(idxCurrentPlayer, &CurrentMap, &pP, &pI, &pT);
                    }
                    ableToRoll = FALSE;
                } else {
                    printf("ERROR!! anda sudah melakukan roll, silahkan input command yang lain!\n<HELP/SKILL/MAP/BUFF/INSPECT/SAVE/UNDO/ENDTURN>\n");
                }
            }

            /* Kalo Commandnya SAVE */
            else if (strcmp(command, "SAVE") == 0) {
                /* Update semua player txt */
                Save(banyakPemain, round, mapname, pU, pT, pP, pI, pC, pSB, pSK, pS1, pS2, pS3, pS4);
                
            }

            /* Kalo Commandnya ENDTURN */
            else if (strcmp(command, "ENDTURN") == 0) {
                if (ableToRoll) {
                    printf("ERROR!! anda belom melakukan roll! -> ROLL\n");
                }
                else {
                    nextPlayer = TRUE;
                }
            }

            /* Kalo Commandnya UNDO */
            else if (strcmp(command, "UNDO") == 0) {
                if (round > 1) {    
                    undoRound(&R,&pP,&pT,&pI,&pC,&pSB,&pSK,&pS1,&pS2,&pS3,&pS4,banyakPemain);
                    idxCurrentPlayer = banyakPemain;
                    nextPlayer = TRUE;
                    round--;
                    if (round > 1) {
                        undoLagi = TRUE;
                    }
                    while ((round > 1) && (undoLagi)) {
                        printf("Apakah ingin undo lagi ke round sebelumnya? (Y/N): ");
                        strcpy(command, "");
                        scanf("%s", command);
                        if (strcmp(command, "Y")==0) {
                            undoRound(&R,&pP,&pT,&pI,&pC,&pSB,&pSK,&pS1,&pS2,&pS3,&pS4,banyakPemain);
                            idxCurrentPlayer = banyakPemain;
                            nextPlayer = TRUE;
                            round--;
                        }
                        else {
                            undoLagi = FALSE;
                        }
                    }
                }
                else {
                    printf("Minimal berada di Round 2 untuk melakukan UNDO.\n");
                }
            }

            else {
                printf("ERROR!! masukkan input command yang benar\n<HELP/SKILL/MAP/BUFF/INSPECT/ROLL/SAVE/UNDO/ENDTURN>\n");
            }

            /* ini buat gantian giliran player */
            if (getPositionOfPlayer(pP, idxCurrentPlayer) == MAP_LENGTH(CurrentMap)) {
                stopGame = TRUE;
                stopProgram = TRUE;
            } 
            else if (nextPlayer) {
                ableToRoll = TRUE;
                pC.isCermin[idxCurrentPlayer] = FALSE;
                pT.isTele[idxCurrentPlayer] = FALSE;
                if (idxCurrentPlayer == banyakPemain) {
                    idxCurrentPlayer = 1;
                    pushRound(&R,pP,pT,pI,pC,pSB,pSK,pS1,pS2,pS3,pS4,banyakPemain);
                    round++;
                    printf("\n||| ROUND %d  |||\n\n", round);

                }
                else {
                    idxCurrentPlayer++;
                }
                
                if (banyaknyaSkill(pS1,pS2,pS3,pS4, idxCurrentPlayer) < 10) {
                    strcpy(getSkill, "");
                    srand(time(0));
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
                    printf("Bonus Pre-Turn Round %d: ", round);
                    printf("%s berhasil ditambahkan ke %s\n", getSkill, pU.uname[idxCurrentPlayer]);
                }
                else {
                    printSkill(pS1,pS2,pS3,pS4, idxCurrentPlayer, &nSkill);
                    printf("Inventory Skill penuh. Apakah mau menghapus salah satu skill untuk mendapat bonus round skill? (ya/no): ");
                    strcpy(command, "");
                    scanf("%s", command);
                    if (strcmp(command, "ya") == 0) {
                        printf("Pilih no skill yang akan dihapus: ");
                        scanf("%d", &skillDelete);
                        deleteSkill(&pS1,&pS2,&pS3,&pS4, idxCurrentPlayer, skillDelete);
                        strcpy(getSkill, "");
                        srand(time(0));
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
                        printf("Bonus Pre-Turn Round %d: ", round);
                        printf("%s berhasil ditambahkan ke %s\n", getSkill, pU.uname[idxCurrentPlayer]);
                    }
                    else {
                        printf("Tidak menerima bonus turn round.\n");
                    }

                }
                printf("\n|| Silahkan bermain player %s! ||\n", pU.uname[idxCurrentPlayer]);
            }
        }
    }
    leaderBoard(pU, pP, idxCurrentPlayer, banyakPemain, adajuara);
}