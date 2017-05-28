#ifndef STRUCT_H
#define STRUCT_H

#include <algorithm>
#include <vector>

#define SIZE 10

using namespace std;

typedef struct it{
    int codigo;
    float peso;
    bool status;
} ITEM;

typedef struct cai{
    float capacidade = SIZE;
    int qnt_itens = 0;
    vector<ITEM> itens;
} BOX;

#endif
