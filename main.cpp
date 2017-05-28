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

int main(){
    vector<ITEM> itens;
    vector<BOX> boxes;

    int qnt_box = 0;
    bool loop;
    int nLines = number_of_lines("heu_e_met_bpk_instances/instance_9.bpk");

    ifstream myfile("heu_e_met_bpk_instances/instance_9.bpk");

    for(int i = 0; i < nLines; i++){
        itens.push_back(ITEM());
        myfile >> itens[i].codigo >> itens[i].peso;
    }

    for(int i = 0; i < nLines; i++)
        itens[i].status = false;

    sort(itens.begin(), itens.end(), descending);

    print_itens(itens, nLines);

    do{
        boxes.push_back(BOX());
        qnt_box++;
        for(int i = 0; i < nLines; i++)
            if(itens[i].peso <= boxes[qnt_box - 1].capacidade && itens[i].status == false){
                boxes[qnt_box - 1].capacidade -= itens[i].peso;
                boxes[qnt_box - 1].itens.push_back(itens[i]);
                boxes[qnt_box - 1].qnt_itens++;

                itens[i].status = true;
            }
        loop = false;
        for(int i = 0; i < nLines; i++)
            if(itens[i].status == false)
                loop = true;
    }while(loop);

    print_result(itens, boxes, qnt_box);

    myfile.close();
    return 0;
}
