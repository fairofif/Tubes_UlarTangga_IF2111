// Mirip dengan player.h tapi disatuin

#ifndef _PLAYERINFO_H
#define _PLAYERINFO_H

#include "../../boolean.h"
#include "../player/player.h"

typedef struct {
    pIsTeleported teleportCondition;
    pIsImune imuneCondition;
    pIsCermin cerminCondition;
    pIsSenterBesar senterbesarCondition;
    pIsSenterKecil senterkecilCondition;
    pIsMesinWaktu mesinwaktuCondition;
    pIsBalingBaling balingCondition;
    pIsPenukar penukarCondition;
    pIsTeknologiGagal teknologigagalCondition;
} pCondition;

/* Info-info yang akan di save: Player*/
typedef struct {
    pUserName userName;
    pPosition position;
    lsNode listSkill; 
    pCondition playerCondition;
    // info map (coming soon) 
} pInfo ;   


#define Pos(P) (P).position
#define LSkill(P) (P).listSkill
#define UName(P) (P).userName
#define PCond(P) (P).playerCondition

#define teleCond(PS) (PS).teleportCondition
#define imunCond(PS) (PS).imuneCondition
#define cerminCond(PS) (PS).cerminCondition
#define sbesarCond(PS) (PS).senterbesarCondition
#define skecilCond(PS) (PS).senterkecilCondition
#define mwaktuCond(PS) (PS).mesinwaktuCondition
#define balingCond(PS) (PS).balingCondition
#define penukarCond(PS) (PS).penukarCondition
#define tekgagalCond(PS) (PS).teknologigagalCondition




#endif