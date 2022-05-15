//
// Created by konstantine on 5/13/22.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <bits/stdc++.h>
using namespace std;


class Calculator{
public:
    Calculator();
    int mainFunction(string s);

private:
    stack<char> operands;
    stack<int> operators;
    string str;
    int nothing = 0;

    //O(n)
    vector<string> tokenSkanner(string s);//working on string and returning resulted vector

    void Shunting_Yard(vector<string> v); //main function
    //O(1)
    void pushInOperands(string num); //pushing numbers in operands stack
    //O(log with base 10(n))
    int strToInt(string num); // convert string into int
    //O(1)
    void lvlOneOrTwoOperation(char newOperator, char a, char b); //after adding level one or two operator this is making old operations
    //O(n)
    void lastStep();//if there are more operators in stack do every operation to get one operant at end
};

#endif