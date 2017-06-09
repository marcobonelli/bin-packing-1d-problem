#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>

#include "struct.h"
#include "function.h"

#define SIZE 10

using namespace std;

int number_of_lines(char arquivo[]){
    ifstream myfile(arquivo);
    string line;
    int i;
    for (i = 0; std::getline(myfile, line); ++i);

    return i;
}

void print_result(vector<ITEM> itens, vector<BOX> boxes, int qnt_box){
    for(int j = 0; j < qnt_box; j++){
        cout << "caixa: " << (j + 1) << " - capacidade restante: " << boxes[j].capacidade << endl << "\t itens: ";
        for(int i = 0; i < boxes[j].qnt_itens; i++)
            cout << boxes[j].itens[i].codigo << " ";
        cout << endl;
    }
    cout << endl;
}

void print_itens(vector<ITEM> itens, int nLines){
    cout << "itens: ";
    for(int i = 0; i < nLines; i++)
        cout << "[ " << itens[i].codigo << " , " << itens[i].peso << " ]" << " ";
    cout << endl << endl;
}

bool ascending(const ITEM &a, const ITEM &b){
    return a.peso < b.peso;
}

bool descending(const ITEM &a, const ITEM &b){
    return a.peso > b.peso;
}

bool none(const ITEM &a, const ITEM &b){
    return false;
}

bool random(const ITEM &a, const ITEM &b){
    return (rand() < rand()) ? true : false;
}
