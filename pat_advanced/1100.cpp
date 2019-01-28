//
// 1100.cpp 
// pat 
// 
// Created by zerl on 2019/1/28. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 
#include <iostream>
using namespace std;
string ge[]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string shi[]={"###","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void func1(string &s){
  int t=stoi(s);
   if (t / 13) cout << shi[t / 13];
    if ((t / 13) && (t % 13)) cout << " ";
    if (t % 13 || t == 0) cout << ge[t % 13];
}
void func2(string &s){
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (s.size() > 4) s2 = s.substr(4, 3);
    for (int j = 1; j <= 12; j++) {
        if (s1 == ge[j] || s2 == ge[j]) t2 = j;
        if (s1 == shi[j]) t1 = j;
    }
    cout << t1 * 13 + t2;
}
int main(){
    int n;
    string s;
    scanf("%d\n",&n);
    for(int i=0;i<n;++i){
        getline(cin, s);
       if(isdigit(s[0])){
            func1(s);
        }else
            func2(s);
    cout <<"\n";
    }
    return 0;
}
