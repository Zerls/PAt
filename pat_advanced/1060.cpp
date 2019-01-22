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
string deal(string s, int& e) {
    
    while(s.length() > 0 && s[0] == '0') {
         s.erase(s.begin());
//         s= s.substr(0); 超时
    }
    if(s[0] == '.') {
        s.erase(s.begin());
        while(s.length() > 0 && s[0] == '0') {
            s.erase(s.begin());
            e--;
        }
    } else{
        int k = 0;
        while(k < s.length() && s[k] != '.') {
            k++;
            e++;
        }
        if(k < s.length()) {
            s.erase(s.begin() + k);
        }
    }
    if(s.length() == 0) {
        e = 0;
    }
    int num = 0,k = 0;
    string res;
    while(num < n) {
        if(k < s.length()) res += s[k++];
        else res += '0';
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

