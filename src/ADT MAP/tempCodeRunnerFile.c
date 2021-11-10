#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../boolean.h"

int main()
{
    char namafile[255];
    int petak, maxroll, telcount;
    char terrain[100];
    int teleport[196];
    char *dummy = "map1.txt";
    boolean valid = FALSE;

    while(!valid){
        scanf("%s", namafile);
        if(strcmp(namafile, dummy) != 0) {
            printf("Masukkan file config salah.\n");
        } else {
            valid = TRUE;
        }
    }



    FILE * fpointer = fopen(namafile, "r");

    fscanf(fpointer, "%d\n", &petak);
    fgets(terrain, 100, fpointer);
    fscanf(fpointer, "%d\n", &maxroll);
    fscanf(fpointer, "%d\n", &telcount);

    for(int i = 0; i < telcount; i = i+2) {
        fscanf(fpointer, "%d %d", &teleport[i], &teleport[i+1]);
    }

    printf("%d\n", petak);
    printf("%s", terrain);
    printf("%d\n", maxroll);
    printf("%d\n", telcount);

    for(int i = 0; i < telcount; i = i+2) {
        printf("%d %d\n", teleport[i], teleport[i+1]);
    }

    fclose(fpointer);
    return 0;