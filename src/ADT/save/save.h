
#ifndef _SAVE_H
#define _SAVE_H

#include "stack.h"
#include "playerinfo.h"

void Save1(int n); 
/*  Menyimpan kondisi player di tengah permainan
    Akses elemen pakai stack (versi 1) 
    n: jumlah player */

void Save2(SEltype State, int n); // n: jumlah player
/*  Menyimpan kondisi player di tengah permainan
    Akses elemen pakai fungsi yang sudah ada di player.c
    SEltype: stack yang berisi info dari player
    n: jumlah player */

#endif
