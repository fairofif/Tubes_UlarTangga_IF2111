#include "console.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    /*********** PREPARATION **********/

    /* Declare variable player */


    /* Declare variable map */
    Map CurrentMap;

    /* Declare main variable */
    boolean stopProgram;
    boolean stopGame;
    boolean nextPlayer;
    int banyakPemain;
    int idxCurrentPlayer;




    /* loop program */
    stopProgram = FALSE;
    while (!stopProgram) {
        /* Prosedur UI Main Menu */

        /* input command */

        /* Kalo commandnya HELP */
            /* Tunjukin command2 yang ada di Main Menu */

        /* Kalo new game */
            /* Input file konfigurasi map yang mau dipake */
            inputConfig();

            /* masukinn jumlah pemain & username pemain2nya */

            /* kasih skill pertama buat para pemain */

            /* set idxPlayer ke 1 */
            idxCurrentPlayer = 1;

        /* Kalo Exit */
            /* stopProgram jadi TRUE */

        /* Kalo load game */

            /* Load player data ke variable2 player */

            /* Load map data ke variable2 map */

            /* Load jumlah pemain dari Neff */

            /* Load idxCurrentPlayer terakhir */

        stopGame = FALSE;
        while ((!stopGame) && (!stopProgram)) {
            nextPlayer = FALSE;
            /* Prosedur UI In Game */

            /* input command */

            /* Kalo commandnya HELP */
                /* Tunjukin command2 yang ada di In Game */

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
                    
            
            /* Kalo Commandnya MAP */
                // showMap(array of char username, idx posisi player);

            /* Kalo Commandnya BUFF */

            /* Kalo Commandnya INSPECT */

            /* Kalo Commandnya ROLL */

            /* Kalo Commandnya SAVE */
                /* Update semua player txt */

                /* Update semua map txt */

            /* Kalo Commandnya ENDTURN */
                nextPlayer = TRUE;

            /* Kalo Commandnya UNDO */
                /* ini kita yang meninggal sebagai developer */


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