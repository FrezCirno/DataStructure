#ifndef TRIPLET_H
#define TRIPLET_H
#include "DS.h"
typedef ElemType* Triplet;

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
Status DestoryTriplet(Triplet &T);
Status Get(Triplet T, int i, ElemType &e);
Status Put(Triplet &T, int i, ElemType e);
Status IsAscending(Triplet T);
Status IsDescending(Triplet T);
Status Max(Triplet T, ElemType &e);
Status Min(Triplet T, ElemType &e);
#endif