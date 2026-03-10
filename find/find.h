#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Data {
	int key;
	void* d;
}Data;

typedef struct HashData {
	Data value;
	struct HashData* next;
}HashData;

Data* createData(int size);
void releaseData(Data* d);
int ordinarySearch(Data* d, int size, Data target);
int binarySearchV1(Data* d, int size, Data target);
int binarySearchV2(Data* d, int size, Data target);
int hashSearch(Data* d, int size, HashData** table, Data target,int po);
HashData** createHashTable(Data* d, int size, int po);
void releaseHashTable(HashData** table, int size);


void checkOrdinary(Data* d, int size);
void checkBinaryV1(Data* d, int size);
void checkBinaryV2(Data* d, int size);
void checkHash(Data* d, int size, HashData** table, int po);
