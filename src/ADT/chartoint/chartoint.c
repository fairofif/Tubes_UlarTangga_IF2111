#include "chartoint.h"

int chartoint(char a[], int len)
{   
    int tel1, tel2;
    int n = 0;
    int value = 0;
    for(int i = len; i > 0; i--) {
        if(CKata.TabKata[i] == BLANK) {
            tel2 = value;
            value = 0;
            n = 0;
        } else {
            int temp = CKata.TabKata[i] - '0';
            value = value + (temp * pow(10, n));
            n++;
        }
    }
    if(inputIndicator > 4) {
        tel1 = value;
        TELEPORT_LAYOUT(CurrentMap)[TELEPORT_NEFF(CurrentMap)] = tel1;
        TELEPORT_LAYOUT(CurrentMap)[TELEPORT_NEFF(CurrentMap) + 1] = tel2;
        TELEPORT_NEFF(CurrentMap) += 2;
    } else {
        if(inputIndicator == 1) {
            MAP_LENGTH(CurrentMap) = value;
        } else if(inputIndicator == 3) {
            MAP_MAXROLL(CurrentMap) = value;
        } else if(inputIndicator == 4) {
            TELEPORT_COUNT(CurrentMap) = value;
        }
    }
    return 0;
}