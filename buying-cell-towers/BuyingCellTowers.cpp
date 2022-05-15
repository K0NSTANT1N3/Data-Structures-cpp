//
// Created by konstantine on 5/13/22.
//

#include<bits/stdc++.h>
using namespace std;

//O(n)
vector<int> buyingCellTowers(vector<int>& towers, vector< vector<int >>& value, vector<int>& forCompare, int start, int end);


int main(){
    int n;
    cin >> n;
    vector<int> towers, forCompare(n);     vector< vector<int> > value(n);
    for(int i = 0; i < n; i++){
        forCompare[i] = -1;
        value[i].push_back(-1);
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        towers.push_back(x);
    }

    vector<int> answer;
    answer = buyingCellTowers(towers, value, forCompare, 0, n - 1);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }

    return 0;}

vector<int> buyingCellTowers(vector<int>& towers, vector< vector<int >>& value, vector<int>& forCompare, int start, int end){
    vector<int> ans;

    //base cases

    if(value[start][0] != -1) return value[start];

    //for zero element
    if(start > end)return ans;

    //for one element
    if(start == end){
        value[start][0] = forCompare[start] = towers[start];   ans.push_back(towers[start]);   return ans;
    }

    //for two element
    if(start + 1 == end){
        value[start][0] = forCompare[start] = towers[start];
        value[end][0] = forCompare[end] = towers[end];

        int wanted = max(towers[start], towers[end]);
        ans.push_back(wanted);      return ans;
    }

    //main case
    vector<int> first = buyingCellTowers(towers, value, forCompare, start + 1 , end);

    vector<int> second = buyingCellTowers(towers, value, forCompare, start + 2 , end);


    if(forCompare[start + 2] + towers[start] < forCompare[start + 1]){
        value[start] = ans = first;
        forCompare[start] = forCompare[start + 1];
    }
    else{
        second.push_back(towers[start]);   value[start] = ans = second;
        forCompare[start] = forCompare[start + 2] + towers[start];
    }
    return ans;

}