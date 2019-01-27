//
// 1132.cpp 
// pat 
// 
// Created by zerl on 2019/1/27. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >>s;
       int a=stoi(s.substr(0,s.size()/2));
       int  b=stoi(s.substr(s.size()/2));
       if(a*b!=0 && stoi(s)%(a*b)==0) printf("Yes\n"); // if(stoi(s)%(stoi(a)*stoi(b))==0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}