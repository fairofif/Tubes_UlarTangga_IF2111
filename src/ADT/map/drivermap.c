#include <stdio.h>
#include "../mesinkar/mesin_kar.c"
#include "../mesinkata/mesin_kata.c"
#include "../map/map.c"
#include "../chartoint/chartoint.c"


int main()
{   
    char dummy[] = "Dito";
    inputConfig(); 
    showMap(dummy ,4);
    return 0;
}