#include "console.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    /*********** PREPARATION **********/

    /* Declare variable player */


    /* Declare variable map */

    /* Declare main variable */
    boolean stopProgram;
    boolean stopGame;
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
            /* Prosedur UI In Game */

            /* input command */

            /* Kalo commandnya HELP */
                /* Tunjukin command2 yang ada di In Game */



            if (idxCurrentPlayer == banyakPemain) {
                idxCurrentPlayer = 1;
            }
            else {
                idxCurrentPlayer++;
            }

        }


    }
}