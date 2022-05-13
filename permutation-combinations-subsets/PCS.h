//
// Created by konstantine on 5/13/22.
//

#ifndef PCS_H
#define PCS_H
#include<bits/stdc++.h>
using namespace std;

//N stands for vector copying every time

//O(N*n!)
vector<vector<int> > Permutations(vector<int>& v);
//O(N*(2^n))
vector< set<int> > Subsets(vector<int>& s);
//O(N*(C(m, k)))
vector< vector<int> > Combinations(vector<int>& s, int k);

#endif

