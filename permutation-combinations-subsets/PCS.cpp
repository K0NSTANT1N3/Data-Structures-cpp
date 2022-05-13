//
// Created by konstantine on 5/13/22.
//

#include"PCS.h"

vector<vector<int> > Permutations(vector<int>& v){
    vector<vector<int> > ans;
    //base case
    if(v.empty()){
        vector<int> empt;       ans.push_back(empt);        return ans;
    }
    //main case
    //for each element take answer individually
    for(int i = 0; i < v.size(); i++){
        //get each element and remove it from subVec
        vector<int> subVec = v;
        int head = subVec[i];
        subVec.erase(subVec.begin() + i);

        //get answer without each element
        vector<vector<int> > tmp = Permutations(subVec);
        int sz = tmp.size();

        //add this element in aswer too and return answer
        for(int j = 0; j < sz; j++){
            tmp[j].push_back(head);
            ans.push_back(tmp[j]);
        }
    }
    return ans;
}



vector< set<int> > Subsets(vector<int>& v){
    vector< set<int> >ans;
    //base case
    //if vector is empty just add empty set in ans and return
    if(v.empty()){
        set<int> empt;     ans.push_back(empt);     return ans;
    }

    //main case
    //get last element and remove it from subVec
    vector<int> subVec = v;
    int head = subVec[subVec.size() - 1];
    subVec.erase(subVec.begin() + subVec.size() - 1);

    //get answer without last element
    ans = Subsets(subVec);
    int sz = ans.size();

    //add with last element too and return
    for(int i = 0; i < sz; i++){
        set<int> eachElement = ans[i];
        eachElement.insert(head);
        ans.push_back(eachElement);
    }
    return ans;
}


vector< vector<int> > Combinations(vector<int>& v, int k){
    vector<vector<int> >ans;

    //base case
    //if vector is empty just add empty vector in ans and return
    if(v.empty() || k == 0){
        vector<int> empt;     ans.push_back(empt);     return ans;
    }

    //case k equal to vector size force us to add this vector in ans and return
    if(k == v.size()){
        ans.push_back(v);      return ans;
    }

    //main case
    //save last element from v and delete this element from v
    int extra = v[v.size() - 1];     v.erase(v.begin() + v.size() - 1);
    //get answer of combinations without last element and with k
    ans = Combinations(v, k);
    //get answer of combinations without last element and with k - 1
    vector<vector<int> > with = Combinations(v, k - 1);
    //combine both answer and return
    for(int i = 0; i < with.size(); i++){
        //add last element in vector "with"
        with[i].push_back(extra);
        ans.push_back(with[i]);
    }
    return ans;
}