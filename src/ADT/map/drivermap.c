#include "../../console.h"
#include "getfileconfig.c"
#include "getmap.h"

void main(){
    // Map CurrentMap;
    getfileconfig();
    
    // inputConfig(&CurrentMap);
    // printConfig(&CurrentMap);
    
    printf("bismillah %s", (*fileconfig));
}