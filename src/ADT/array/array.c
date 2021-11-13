#include <stdio.h>
#include "array.h"

void MakeEmpty (TabInt *T) {
    int i;
    for (i = 0; i < IdxMax; i++) {
        T -> TI[i] = IdxUndef;
    }
    T -> Neff = 0;
}

int NbElmt (TabInt T) {
    if (T.TI[0] == IdxUndef) {
        return 0;
    }
    return T.Neff;
}

int MaxNbEl (TabInt T) {
    return IdxMax - T.Neff;
}

IdxType GetFirstIdx (TabInt T) {
    return IdxMin;
}

IdxType GetLastIdx (TabInt T) {
    return IdxMax;
}

ElType GetElmt (TabInt T, IdxType i) {
    return T.TI[i];
}

void SetTab (TabInt Tin, TabInt *Tout) {
    *Tout = Tin;
}

void SetEl (TabInt *T, IdxType i, ElType v) {
    T->TI[i] = v;
}

void SetNeff (TabInt *T, IdxType N) {
    T->Neff = N;
}

boolean IsIdxValid (TabInt T, IdxType i) {
    return (i >= 0 && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i) {
    return (i >= 0 && i <= T.Neff);
}

boolean IsEmpty (TabInt T) {
    return (T.Neff == 0);
}

boolean IsFull (TabInt T) {
    return (IdxMax == T.Neff);
}

