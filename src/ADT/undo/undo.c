#include <stdio.h>
#include "stack.h"
#include "stack.c"
#include "round.h"
#include "round.c"

void undo (Stack state){
    while (!IsEmpty(state)){
        char s [10];
        SEltype last_state;
        last_state = undoRound();
        Pop(&state, &last_state);
        printf("Berhasil melakukan undo! State permainan berubah menjadi akhir pada ronde x \n");
        if (!IsEmpty(state)){
            printf("Apakah ingin melakukan undo lagi (Y/N) ? \n");
            scanf("%s",s);
                if (strcmp(s, "N")){
                    break;
                }
                else if (strcmp(s, "Y")){
                    continue;
                }
        }
    }
}