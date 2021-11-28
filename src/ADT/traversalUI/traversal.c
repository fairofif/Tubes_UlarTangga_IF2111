#include "traversal.h"


void welcome()
{
    printf("  _________      .__                         __    ________          __                             \n");   
    printf(" /   _____/ ____ |  | _____    _____ _____ _/  |_  \\______ \\ _____ _/  |______    ____    ____      \n");
    printf(" \\_____  \\_/ __ \\|  | \\__  \\  /     \\\\__  \\\\   __\\  |    |  \\\\__  \\\\   __\\__  \\  /    \\  / ___\\     \n");
    printf(" /        \\  ___/|  |__/ __ \\|  Y Y  \\/ __ \\|  |    |    `   \\/ __ \\|  |  / __ \\|   |  \\/ /_/ |    \n");
    printf("/_______  /\\___  >____(____  /__|_|  (____  /__|   /_______  (____  /__| (____  /___|  /\\___  /     \n");
    printf("        \\/     \\/          \\/      \\/     \\/               \\/     \\/          \\/     \\//_____/\n");
    printf("\n");
    printf("/-------------------------------------------------------------------------------------------/|\n");
    printf("+------------------------------------------------------------------------------------------+ |\n");
    printf("| Masukkan command LOAD untuk memulai permainan dari penyimpanan terakhir                  | |\n");
    printf("| Masukkan command NEWGAME untuk memulai permainan baru                                    | |\n");
    printf("| Masukkan command HELP untuk memunculkan command bantuan                                  | |\n");
    printf("| Masukkan command EXIT untuk keluar dari permainan                                        | /\n");
    printf("+------------------------------------------------------------------------------------------+\n");
};

void start()
{
    printf(" ______   ______  ______   ______  ______                       \n");
    printf("/\\  ___\\ /\\__  _\\/\\  __ \\ /\\  == \\/\\__  _\\            \n");
    printf("\\ \\___  \\\\/_/\\ \\/\\ \\  __ \\\\ \\  __/\\/_/\\ \\/        \n");
    printf(" \\/\\_____\\  \\ \\_\\ \\ \\_\\ \\ \\\\ \\_\\ \\_\\ \\ \\_\\ _ \n");
    printf("  \\/_____/   \\/_/  \\/_/\\/_/ \\/_/ /_/  \\/_/|_|_               \n");
    printf("\\___________________________________________|_|_\n");
    printf(" \\____________________________________________|_|_\n");
    printf("  \\_____________________________________________|_|\n");
};

void help()
{
    printf("+----------------------------------------------------------------------------------------+ \n");
    printf("|                                       -Help-                                           | \n");
    printf("+----------------------------------------------------------------------------------------+ \n");
    printf("| NEWGAME : Memulai permainan baru dengan memasukkan kode map                            | \n");
    printf("| LOAD	  : Memulai permainan dari penyimpanan terakhir                                  | \n");
    printf("| SKILL	  : Memakai dan membuang skill yang dimiliki                                     | \n");
    printf("| MAP	  : Menampilkan state peta saat ini                                              | \n");
    printf("| BUFF	  : Menampilkan daftar buff yang dimiliki pemain                                 | \n");
    printf("| INSPECT : Menunjukkan informasi teleport pada petak tertentu                           | \n");
    printf("| ROLL	  : Memutar dadu                                                                 | \n");
    printf("| SAVE	  : Menyimpan state permainan (Command ini hanya dapat digunakan setelah roll)   | \n");
    printf("| ENDTURN : Mengakhiri giliran pemain (Command ini hanya dapat digunakan setelah roll)   | \n");
    printf("| UNDO	  : Mengulang ke ronde sebelumnya                                                | \n");
    printf("| EXIT	  : Keluar dari permainan                                                        | \n");
    printf("+----------------------------------------------------------------------------------------+ \n");
};

void leaderBoard(pUserName pU, pPosition pP, int idxCurrentPlayer, int banyakPemain)
{
    printf("\nCONGRATULATIONS!!\n");
    printf("%s telah mencapai petak terakhir!\n", pU.uname[idxCurrentPlayer]);
    
    /* Sort Leaderboard berdasarkan posisi akhir */
    for (int i = 1; i <= banyakPemain; i++) {     
        for (int j = i+1; j <= banyakPemain; j++) {     
            if((pP.pos[i] < pP.pos[j])){
                int tempP;
                tempP = pP.pos[i];
                pP.pos[i] = pP.pos[j];
                pP.pos[j] = tempP;

                char tempU[16];
                strcpy(tempU,pU.uname[i]);
                strcpy(pU.uname[i],pU.uname[j]);
                strcpy(pU.uname[j],tempU);
            }
        }  
    }

    /* Menampilkan leaderboard pada layar*/
    printf("\nLEADERBOARD\n");
    for (int i = 1; i <= banyakPemain; i++) {
        printf("%d. %s dengan posisi akhir di %d\n", i, pU.uname[i], pP.pos[i]);  
    }    
}
