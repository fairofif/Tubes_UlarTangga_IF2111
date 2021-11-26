#ifndef _MAP_H
#define _MAP_H

#include "../../console.h"

#define Nil NULL
#define MaxMap 100

typedef struct {
    char Layout[MaxMap+1]; //layout map berisi ...#..#..
    int Neff;
    int Length; //nanti buat ngecek sama ga kaya MapLength
} MapLayout;

typedef struct {
    int Layout[198];
    int Neff;
    int Count;
} TeleportLayout;

typedef struct {
    MapLayout ConfigMap; //akses Map.Layout dan Map.LayoutLength
    int MaxRoll; //max roll pada dadu
    TeleportLayout Teleport; //jumlah teleport
} Map;

#define MAP_LENGTH(m) (m).ConfigMap.Length
#define MAP_NEFF(m) (m).ConfigMap.Neff
#define MAP_LAYOUT(m) (m).ConfigMap.Layout
#define MAP_LAYOUT_LENGTH(m) (m).ConfigMap.LayoutLength
#define MAP_MAXROLL(m) (m).MaxRoll
#define TELEPORT_LAYOUT(m) (m).Teleport.Layout
#define TELEPORT_NEFF(m) (m).Teleport.Neff
#define TELEPORT_COUNT(m) (m).Teleport.Count

extern int inputIndicator;

void inputConfig(Map *CurrentMap);
/* Memasukkan input berupa nama file konfigurasi map yang akan dimainkan.
   I.S. : tidak ada map yang diinput/dipilih
   F.S. : fpointer menunjuk pada file yang akan digunakan sebagai file konfigurasi
          input */

void readConfig(Map *CurrentMap);
/* Membaca teks pada file txt dari nama file konfigurasi yang dipilih.
    I.S. : tidak ada nilai yang disimpan
    F.S. : map yang diinput akan menghasilkan panjang map yang akan dimainkan, 
           layout mapnya, roll maksimal yang ditentukan, dan jumlah teleport yang 
           ada */

void assignConfig(Map *CurrentMap);
/* Memasukkan input bacaan dari file konfigurasi ke dalam variabel pointer yang digunakan
   selama permainan.
   I.S. : pointer currentMap tidak menunjuk kemana-mana
   F.S. : pointer menunjuk input sesuai dengan format yang ada */

void printConfig(Map *CurrentMap);
/* Melakukan pencetakan semua input yang ada pada file konfigurasi yang telah ditunjuk pointer.
   F.S. : output berupa semua setup map yang ingin dimainkan */

void showMap(pPosition (*pP), pUserName (*pU), int idxCurrentPlayer, Map *CurrentMap);
/* Mencetak peta yang akan/sedang dimainkan.
   F.S. : output berupa layout map yang sedang dimainkan */

int rollDice(int max);
/* Mengembalikan roll dadu random yang tidak sama dengan */

void movePlayer(int roll, int idxCurrentPlayer, Map *CurrentMap, pPosition (*pP));

void inspectMap(Map *CurrentMap);

void forceMove(int roll, int idxCurrentPlayer, Map *CurrentMap, pPosition (*pP), pIsImune (*pI));

void teleport (int idxCurrentPlayer, Map *CurrentMap, pPosition (*pP), pIsImune (*pI), pIsTeleported (*pT));

#endif