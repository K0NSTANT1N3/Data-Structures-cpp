//
// Created by konstantine on 5/13/22.
//

#include "Calculator.h"

//public functions

Calculator::Calculator(){
}

int Calculator::mainFunction(string s){
    vector<string> v = tokenSkanner(s);

    Shunting_Yard(v);
    if(!operators.empty()){
        lastStep();
    }
    return operands.top();
}

//private functions


vector<string> Calculator::tokenSkanner(string s){
    vector<string> res;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            string tmp = "";    tmp += s[i];    res.push_back(tmp);
        }
        if(s[i] >= '0' && s[i] <= '9'){
            string tmp = "";
            while(s[i] >= '0' && s[i] <= '9' && i < s.size()){
                tmp += s[i];
                i++;
            }
            i--;
            res.push_back(tmp);
        }
    }
    return res;
}

void Calculator::Shunting_Yard(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        if(v[i][0] >= '0' && v[i][1] <= '9'){
            pushInOperands(v[i]);
        }
        else{
            if(v[i][0] == '('){
                operators.push('(');
            }
            if(v[i][0] == '*' || v[i][0] == '/'){
                if(!operators.empty()) lvlOneOrTwoOperation(v[i][0], '*', '/');
                else operators.push(v[i][0]);
            }
            if(v[i][0] == '+' || v[i][0] == '-'){
                if(!operators.empty()) lvlOneOrTwoOperation(v[i][0], '+', '-');
                else operators.push(v[i][0]);
            }
            if(v[i][0] == ')'){
                lvlOneOrTwoOperation(v[i][0], '+', '-');
                if(operators.top() == '('){
                    operators.pop();
                }
            }
        }
    }
}

void Calculator::pushInOperands(string num){
    int number = strToInt(num);
    operands.push(number);
}

int Calculator::strToInt(string num){
    if(num.size() == 1){
        int a = num[0] - '0';
        return a;
    }
    string subNum = num.substr(0, num.size() -1);
    string last = num.substr(num.size() - 1, 1);

    int left = strToInt(subNum);
    int right = strToInt(last);
    int result = (left * 10) + right;
    return result;
}

void Calculator::lvlOneOrTwoOperation(char newOperator, char a, char b){

    char oldOperator = operators.top();
    while(oldOperator == '*' || oldOperator == '/' || oldOperator == a || oldOperator == b){
        operators.pop();
        int first = operands.top();  operands.pop();
        int second = operands.top(); operands.pop();
        int ans = INT_MAX;

        if(oldOperator == '*')ans = second * first;
        else if(oldOperator == '/')ans = second * first;
        else if(oldOperator == a)ans = second + first;
        else if(oldOperator == b)ans = second - first;

        if(ans != INT_MAX) operands.push(ans);

        if (operators.empty()) break;
        oldOperator = operators.top();
    }
    if(newOperator != ')')operators.push(newOperator);
}

void Calculator::lastStep(){
    while(!operators.empty()){
        char oldOperator = operators.top();      operators.pop();
        int first = operands.top();              operands.pop();
        int second = operands.top();             operands.pop();
        int ans = INT_MAX;

        switch(oldOperator){
            case '*': ans = second * first; break;
            case '/': ans = second / first; break;
            case '+': ans = second + first; break;
            case '-': ans = second - first; break;
        }

        if(ans != INT_MAX) operands.push(ans);
    }
}