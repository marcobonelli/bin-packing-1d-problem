#include "struct.h"

using namespace std;

#ifndef function_H
#define function_H

int number_of_lines(char arquivo[]);

void print_result(vector<ITEM> itens, vector<BOX> boxes, int qnt_box);

void print_itens(vector<ITEM> itens, int nLines);

bool ascending(const ITEM &a, const ITEM &b);

bool descending(const ITEM &a, const ITEM &b);

bool none(const ITEM &a, const ITEM &b);

bool random(const ITEM &a, const ITEM &b);

#endif
