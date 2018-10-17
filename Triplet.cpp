#include"DS.h"

typedef ElemType* Triplet;

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
Status DestoryTriplet(Triplet &T);
Status Get(Triplet T, int i, ElemType &e);
Status Put(Triplet &T, int i, ElemType e);
Status IsAscending(Triplet T);
Status IsDescending(Triplet T);
Status Max(Triplet T, ElemType &e);
Status Min(Triplet T, ElemType &e);

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3) {
	T = (ElemType*)malloc(3 * sizeof(ElemType));
	if (!T)exit(OVERFLOW);
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return OK;
}//InitTriplet

Status DestoryTriplet(Triplet &T) {
	free(T);
	T = NULL;
	return OK;
}//DestoryTriplet

Status Get(Triplet T, int i, ElemType &e) {
	if (i < 1 || i > 3)return ERROR;
	e = T[i - 1];
	return OK;
}//Get

Status Put(Triplet &T, int i, ElemType e) {
	if (i < 1 || i > 3)return ERROR;
	T[i - 1] = e;
	return OK;
}//Put

Status IsAscending(Triplet T) {
	return (T[0] <= T[1] && T[1] <= T[2]);
}//IsAscending

Status IsDescending(Triplet T) {
	return(T[0] >= T[1] && T[1] >= T[2]);
}//IsDescending

Status Max(Triplet T, ElemType &e) {
	e = (T[0] >= T[1]) ? ((T[0] >= T[2]) ? T[0] : T[2]) : ((T[1] >= T[2]) ? T[1] : T[2]);
	return OK;
}//Max

Status Min(Triplet T, ElemType &e) {
	e = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2]) : ((T[1] <= T[2]) ? T[1] : T[2]);
	return OK;
}//Min
