#ifndef	_ROUND_H
#define _ROUND_H
#include "../../console.h"

#define Nil NULL

/* Definisi Type Stack */
typedef struct tRoundNode *addressRound;
typedef struct tRoundNode {
	int position[5];
    boolean teleported[5];
    boolean imunity[5];
    boolean cermin[5];
    boolean senterB[5];
    boolean senterK[5];
    char listskill[5][11][30];
    addressRound next;
} RoundNode;

typedef struct {
	addressRound Latest; 
} Round;

#define LATESTROUND(p) (p).Latest
#define NEXTROUND(p) (p)->next
#define POSITIONROUND(p) (p)->position
#define TELEPORTEDROUND(p) (p)->teleported
#define IMUNITYROUND(p) (p)->imunity
#define CERMINROUND(p) (p)->cermin
#define SENTERBROUND(p) (p)->senterB
#define SENTERKROUND(p) (p)->senterK
#define SKILLROUND(p) (p)->listskill

void createEmptyRound (Round *R);

addressRound newRoundNode();

void pushRound (Round *R, pPosition pP, pIsTeleported pT, pIsImune pI,
pIsCermin pC, pIsSenterBesar pSB, pIsSenterKecil pSK, Skill pS1,
Skill pS2, Skill pS3, Skill pS4, int nPlayer);

void undoRound (Round *R, pPosition *pP, pIsTeleported *pT, pIsImune *pI,
pIsCermin *pC, pIsSenterBesar *pSB, pIsSenterKecil *pSK, Skill *pS1,
Skill *pS2, Skill *pS3, Skill *pS4, int nPlayer);

#endif