//
// 1060.cpp 
// pat 
// 
// Created by zerl on 2019/1/22. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <string>
using namespace std;
int n;
static string deal(string s, int& e) {

    while (s.size()>0 && s[0]=='0') {
        s.erase(s.begin());
    }
    if(s[0]=='.'){
        s.erase(s.begin());
        while (s.size()>0 && s[0]=='0') { //while (s.size()>0 && s[0]!='0') {
            s.erase(s.begin());
            e--;
        }
    }else{
        int k=0;
        while (k<s.size() && s[k]!='.') { //while (s.size()>0 && s[0]!='.') {
           // s.erase(s.begin());
            k++;
            e++;
        }
        if(k <s.size()) s.erase(s.begin()+k);
    }
    if(s.size()==0) e=0;
    string res;
    int num=0,k=0;
    while (num <n) {
        if(k<s.size()) //if(k<n)
            res+=s[k++];
        else
            res+='0';
        num++;
    }
    return res;
}
int i1060() {
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if(s3 == s4 && e1 == e2) {
        cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
    } else {
        cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
    }
    return 0;
}

