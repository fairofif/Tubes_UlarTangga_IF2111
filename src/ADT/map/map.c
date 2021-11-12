#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../boolean.h"
#include "map.h"

FILE * fpointer;
int *petak, *maxroll, *telcount;

void inputConfig() 
{
    char namafile[255];
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

    fpointer = fopen(namafile, "r");

    readConfig();

}

void readConfig()
{   
    STARTKATA();

    fclose(fpointer);
}

int main()
{
    inputConfig();
    
    return 0;
}