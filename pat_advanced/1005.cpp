//
// 1005.cpp 
// pat 
// 
// Created by zerl on 2018/10/19. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;

const string STR[]={
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int i1005() {
    //freopen("1005.txt","r",stdin);
    int sum=0;
    string s;
    cin >> s;
    
    for (int i = 0; i < s.length();  ++i)
        sum += s[i]-'0';
    s=to_string(sum);
    
    for (int i =0; i<s.length(); ++i)
        cout << (i == 0 ? "":" ") << STR[s[i]-'0'];
    cout << endl;
    
    return 0;
}
