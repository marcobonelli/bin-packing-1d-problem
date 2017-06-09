#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>

#include "struct.h"
#include "function.h"
#include "local_search.h"

#define SIZE 10

void local_search(vector<ITEM> &itens, vector<BOX> &boxes, int &qnt_box){
    bool loop, localSearch;

    do{
        loop = false;
        for(int c1 = 0; c1 < qnt_box; c1++){
            if(boxes[c1].capacidade != 0 && boxes[c1].qnt_itens > 1){
                for(int c2 = c1 + 1; c2 < qnt_box; c2++){
                    int best_change = 0, change[] = {0, 0};
                    localSearch = false;
                    for(int i1 = 0; i1 < boxes[c1].qnt_itens; i1++){
                        for(int i2 = 0; i2 < boxes[c2].qnt_itens; i2++){
                            if(boxes[c2].itens[i2].peso > boxes[c1].itens[i1].peso){
                                int dif = boxes[c2].itens[i2].peso - boxes[c1].itens[i1].peso;
                                if(dif <= boxes[c1].capacidade && boxes[c1].capacidade - dif >= best_change){
                                    best_change = boxes[c1].capacidade - dif;
                                    change[0] = i1;
                                    change[1] = i2;
                                    localSearch = true;
                                }
                            }
                        }
                    }
                    if(localSearch){
                        cout << "---> trocar o item " << (boxes[c1].itens[change[0]].codigo) << " com o item " << (boxes[c2].itens[change[1]].codigo) << endl;

                        boxes[c1].capacidade -= (boxes[c2].itens[change[1]].peso - boxes[c1].itens[change[0]].peso);
                        boxes[c2].capacidade += (boxes[c2].itens[change[1]].peso - boxes[c1].itens[change[0]].peso);

                        ITEM itemAUX = boxes[c1].itens[change[0]];
                        boxes[c1].itens[change[0]] = boxes[c2].itens[change[1]];
                        boxes[c2].itens[change[1]] = itemAUX;
                    }
                }
            }
        }
    }while(loop);

    cout << endl;

    print_result(itens, boxes, qnt_box);

    for(int c1 = 0; c1 < qnt_box; c1++){
        for(int c2 = c1 + 1; c2 < qnt_box; c2++){
            if(boxes[c1].capacidade + boxes[c2].capacidade >= SIZE){
                for(int i2 = 0; i2 < boxes[c2].qnt_itens; i2++){
                    cout << "---> juntar a caixa " << (c1 + 1) << " com a caixa " << (c2 + 1) << endl;

                    boxes[c1].itens.push_back(boxes[c2].itens.at(i2));
                    boxes[c1].qnt_itens++;
                    boxes[c1].capacidade -= boxes[c1].itens[boxes[c1].qnt_itens - 1].peso;
                }
                boxes.erase(boxes.begin() + c2);
                qnt_box--;
            }
        }
    }

    cout << endl;

    print_result(itens, boxes, qnt_box);
}
