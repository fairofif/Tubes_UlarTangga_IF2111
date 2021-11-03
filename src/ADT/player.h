#ifndef _PLAYER_H
#define _PLAYER_H
#include "../boolean.h"
#include <stdlib.h>
#define Nil NULL

typedef int ElType;

typedef struct listSkillNode *address;
typedef struct listSkillNode {
    address nextskill;
    char skillName[20];
} lsNode;

typedef struct {
    address addrFirstSkill;
} pSkill;

/* Player menggunakan circular linked list */
typedef struct playerNode *address;
typedef struct playerNode {
    ElType position;
    boolean isTeleportedBefore;
    boolean isImmune;
    address next;
    pSkill skills;
    char playerName[16];
} pNode;

typedef struct {
    address addrFirstPlayer;
} Player;

#define NEXT(p) (p)->next
#define POS(p) (p)->position
#define ISTELE(p) (p)->isTeleportedBefore
#define ISIMMUNE(p) (p)->isImmune
#define SKILLS(p) (p)->skills
#define SKILLNAME(p) (p)->skillName[20]
#define PNAME(p) (p)->playerName[16]
#define ADDR_FIRSTSKILL(p) (p).addrFirstSkill
#define ADDR_FIRSTPLAYER(p) (p).addrFirstPlayer
#define NEXTSKILL(p) (p)->nextskill

void createEmptyPlayerList (Player *PL);
/*  Prosedur membuat List pemain kosong
    I.S sembarang
    F.S list player kosong
*/

void createEmptyPlayerSkillsList (pSkill *PR);

void inputPlayerList (Player *PL, int n);
/*
    Prosedur mengisi list player
    I.S kosong, N <= 4
    F.S list player berisi n player
*/

address newSkillNode ();

address newPlayerNode ();

const char* randomSkillGenerator();

void getSkill (Player *PL, char plName[16]);


#endif