//
// 1024.cpp 
// pat 
// 
// Created by zerl on 2019/1/24. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
using namespace std;
static string s;
static void add(string &t){
    int carry=0;
    for (int i=(int)s.size()-1; i>=0; --i) {
        int num=carry+s[i]-'0'+t[i]-'0'; //carry 进位加在这里
        s[i]=num%10+'0';
        carry=num/10;
    }
    if(carry) s='1'+s;
}
int i1024(){
    int cnt,i;
    cin >> s >> cnt;
    for (i=0; i<=cnt; ++i) {
        string t=s;
        reverse(t.begin(),t.end());
        if(t==s || i==cnt) break;//if(t==s ) 避免多加一次
        add(t);
    }
    cout << s <<"\n"<< i<<"\n";
    return 0;
}
