#include<stdio.h>
#include<string.h>

int main(){    
    printf("  _________      .__                         __    ________          __                             \n");   
    printf(" /   _____/ ____ |  | _____    _____ _____ _/  |_  \\______ \\ _____ _/  |______    ____    ____      \n");
    printf(" \\_____  \\_/ __ \\|  | \\__  \\  /     \\\\__  \\\\   __\\  |    |  \\\\__  \\\\   __\\__  \\  /    \\  / ___\\     \n");
    printf(" /        \\  ___/|  |__/ __ \\|  Y Y  \\/ __ \\|  |    |    `   \\/ __ \\|  |  / __ \\|   |  \\/ /_/ |    \n");
    printf("/_______  /\\___  >____(____  /__|_|  (____  /__|   /_______  (____  /__| (____  /___|  /\\___  /     \n");
    printf("        \\/     \\/          \\/      \\/     \\/               \\/     \\/          \\/     \\//_____/\n");
    int pemain, i, j, flag=0;
    char namapemain[100][100];
    printf("Berapa orang yang akan bermain :");
    scanf("%d", &pemain);
    if (pemain >=2 && pemain <=4){
        for (int i=0;i<pemain;i++){
            do {
            flag = 0;
            printf ("Nama orang ke-%d : ",i+1);
		    scanf ("%s",&namapemain[i]); 
            for (int j=0;j<i;j++){
                if(strcmp (namapemain[i], namapemain[j]) ==0){
                    flag = 1;
                    printf("Nama sudah dipakai, Silahkan masukkan nama yang lain!\n");
                    break;
                }
            }
            } while (flag == 1);
        }
        printf("Letsgooooo.........\n");
    }
    else{
        printf("Masukkan tidak valid\n");
    }
    return 0;
}