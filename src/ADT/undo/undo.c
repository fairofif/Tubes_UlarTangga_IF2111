#include <stdio.h>
#include "stack.h"
#include "stack.c"

void undo (Stack state){
    while (!IsEmpty(state)){
        char s [10];
        // jadi setiap selesai melakukan ronde, info pada akhir rondenya tuh langsung disave ke state dalam bentuk last_state
        // jadi nanti tinggal dipop last_statenya
        SEltype last_state;
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