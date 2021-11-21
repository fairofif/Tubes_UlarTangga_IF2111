#include <stdio.h>;
#include "traversal.h";

void welcome()
{
    printf("  _________      .__                         __    ________          __                             \n");   
    printf(" /   _____/ ____ |  | _____    _____ _____ _/  |_  \\______ \\ _____ _/  |______    ____    ____      \n");
    printf(" \\_____  \\_/ __ \\|  | \\__  \\  /     \\\\__  \\\\   __\\  |    |  \\\\__  \\\\   __\\__  \\  /    \\  / ___\\     \n");
    printf(" /        \\  ___/|  |__/ __ \\|  Y Y  \\/ __ \\|  |    |    `   \\/ __ \\|  |  / __ \\|   |  \\/ /_/ |    \n");
    printf("/_______  /\\___  >____(____  /__|_|  (____  /__|   /_______  (____  /__| (____  /___|  /\\___  /     \n");
    printf("        \\/     \\/          \\/      \\/     \\/               \\/     \\/          \\/     \\//_____/\n");
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
    printf("| SKILL	  : Memakai dan membuang skill yang dimiliki                                     | \n");
    printf("| MAP	  : Menampilkan state peta saat ini                                              | \n");
    printf("| BUFF	  : Menampilkan daftar buff yang dimiliki pemain                                 | \n");
    printf("| INSPECT : Menunjukkan informasi teleport pada petak tertentu                           | \n");
    printf("| ROLL	  : Memutar dadu                                                                 | \n");
    printf("| SAVE	  : Menyimpan state permainan (Command ini hanya dapat digunakan setelah roll)   | \n");
    printf("| ENDTURN : Mengakhiri giliran pemain (Command ini hanya dapat digunakan setelah roll)   | \n");
    printf("| UNDO	  : Mengulang ke ronde sebelumnya                                                | \n");
    printf("+----------------------------------------------------------------------------------------+ \n");
};