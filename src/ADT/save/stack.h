// buat info player -> save and load

#ifndef _STACK_H
#define _STACK_H

#include "../../boolean.h"
#include "playerinfo.h"
#include "../map/map.h"

#define Nil NULL
#define CAPACITY 100

/* pInfo = Player*/
/* SEltype = Sinfotype*/
typedef struct {
    pInfo player1;
    pInfo player2;
    pInfo player3;
    pInfo player4;
    Map dataMap;
    int turn;
} SEltype;

typedef struct {
    SEltype buffer[CAPACITY]; // array buat nyimpen infoplayer (stack elemen type)
    int TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).buffer[(S).TOP]

#define P1Info(PI) (PI).player1
#define P2Info(PI) (PI).player2
#define P3Info(PI) (PI).player3
#define P4Info(PI) (PI).player4
#define DataMap(PI) (PI).dataMap
#define TurnInfo(PI) (PI).turn

void CreateState(SEltype *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Stack s yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0..CAPACITY-1 */
/* Ciri stack kosong: idxTop bernilai IDX_UNDEF */

boolean IsEmptyStack(Stack S);
// * Mengirim true jika stack kosong

boolean IsFull(Stack S);
// * Mengirim true jika tabel penampung Snilai elemen stack penuh

boolean IsFirstState(Stack S);
// * Mengirim true jika gamestate paling awal


void StartTurn(Stack *S, pInfo P1, pInfo P2, Map DataMap, int Turn);
// * I.S. sembarang
// * F.S. Membuat sebuah stack S yang kosong berkapasitas MaxSEl
// * Memulai turn

void ResetStack(Stack *S);
// * I.S. Stack terdefinisi, mungkin kosong
// * F.S. Menghabiskan isi sebuah stack S, dan mengisinya dengan InfoTop saat
// *      sebelum dihabisi

void Push(Stack *S, SEltype X);
// * Menambahkan X sebagai elemen Stack S.
// * I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
// * F.S. X menjadi TOP yang baru,TOP bertambah 1

void Pop(Stack *S, SEltype *X);
// * Menghapus X dari Stack S.
// * I.S. S  tidak mungkin kosong
// * F.S. X adalah Snilai elemen TOP yang lama, TOP berkurang 1


#endif