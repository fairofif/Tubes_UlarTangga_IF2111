#ifndef _MAP_H
#define _MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../boolean.h"
#include "../mesinkata/mesin_kata.h"


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


extern Map CurrentMap;
extern int inputIndicator;

void inputConfig();
/* Memasukkan input berupa nama file konfigurasi map yang akan dimainkan.
   I.S. : tidak ada map yang diinput/dipilih
   F.S. : fpointer menunjuk pada file yang akan digunakan sebagai file konfigurasi
          input */

void readConfig();
/* Membaca teks pada file txt dari nama file konfigurasi yang dipilih.
    I.S. : tidak ada nilai yang disimpan
    F.S. : map yang diinput akan menghasilkan panjang map yang akan dimainkan, 
           layout mapnya, roll maksimal yang ditentukan, dan jumlah teleport yang 
           ada */

void charToInt();
/* Mengubah char ke int untuk input yang merupakan integer seharusnya.
    I.S. : input dari file konfigurasi yang merupakan integer tapi dituliskan dalam char
           pada array
    F.S. : input berupa array of char menjadi int */


void assignConfig();

void printConfig();

void showMap();

#endif
