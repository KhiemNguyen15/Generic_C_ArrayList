#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "data.h"

typedef struct ArrayList ArrayList;
typedef struct ArrayList List;

struct ArrayList
{
    Data *arr;        
    size_t size;
    size_t capacity;
};

typedef bool (*EqualityFunction)(const void *, const void *);

ArrayList *createList(void);
ArrayList *listClone(const ArrayList *list);

void listAdd(ArrayList **listPtr, void *val);
void listAddAll(ArrayList **listPtr, const ArrayList *toAdd);
void listInsert(ArrayList **listPtr, void *val, const size_t index);
void listSet(ArrayList **listPr, void *val, const size_t index);
void listRemove(ArrayList **listPtr, const size_t index);
void listRemoveElement(ArrayList **listPtr, const void *toRemove, EqualityFunction compare);
void listRemoveRange(ArrayList **listPtr, const size_t start, const size_t end);
void listRemoveAll(ArrayList **listPtr, const ArrayList *toRemove, EqualityFunction compare);
void listClear(ArrayList **listPtr);
void listSort(ArrayList **listPtr, __compar_fn_t func);

void *listGet(const ArrayList *list, const size_t index);
bool listContains(const ArrayList *list, const void *toFind, EqualityFunction compare);
int listIndexOf(const ArrayList *list, const void *toFind, EqualityFunction compare);
int listLastIndexOf(const ArrayList *list, const void *toFind, EqualityFunction compare);
size_t listSize(const ArrayList *list);
bool listIsEmpty(const ArrayList *list);

void reallocList(ArrayList **listPtr, const bool isUp);
void freeList(ArrayList **listPtr);

#endif