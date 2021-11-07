#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int petak, maxroll, telcount;
    char terrain[100];
    int teleport[196];

    FILE * fpointer = fopen("map1.txt", "r");

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
}