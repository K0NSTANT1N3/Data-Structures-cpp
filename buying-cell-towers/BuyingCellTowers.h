//
// Created by konstantine on 6/5/22.
//

#ifndef DATA_STRUCTURES_CPP_BUYINGCELLTOWERS_H
#define DATA_STRUCTURES_CPP_BUYINGCELLTOWERS_H

#include "bits/stdc++.h"
using namespace std;

class BuyingCellTowers {
public:
    BuyingCellTowers();

private:
    vector<int> Process(vector<int>& towers, vector< vector<int >>& value, vector<int>& forCompare, int start, int end);
};


#endif //DATA_STRUCTURES_CPP_BUYINGCELLTOWERS_H
