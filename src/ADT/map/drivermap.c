#include "../../console.h"
#include "getfileconfig.c"
#include "getmap.h"

void main(){
    Map CurrentMap;
    inputConfig(&CurrentMap);
    printConfig(&CurrentMap);
}