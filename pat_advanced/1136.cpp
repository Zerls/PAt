//
// 1136.cpp 
// pat 
// 
// Created by zerl on 2019/1/9. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
using namespace std;

static string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}


static string add(string s1,string s2){
    string s=s1;
    int carry=0;
    for (int i=s1.size()-1; i>=0; --i) {
        s[i]=(s1[i]-'0'+s2[i]-'0'+carry)%10+'0';
        carry=(s1[i]-'0'+s2[i]-'0'+carry)/10;
    }
    if(carry>0) s="1"+s;
    return s;
}
int i1136(){
    string s,num;
    cin >> s;
    int n=10;
    while (n--) {
        if(s == rev(s)){
            cout << s << " is a palindromic number.\n";
            return 0;
        }
        num=add(s,rev(s));
        cout <<s << " + "<< rev(s)<<" = "<< num <<"\n";
        s=num;
    }
    cout << "Not found in 10 iterations.\n";
    return 0;
}
