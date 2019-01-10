//
// 1038.cpp 
// pat 
// 
// Created by zerl on 2019/1/10. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static bool cmp0(string s1, string s2){
    return s1+s2 < s2+s1;
}
static string str[10010];

int i1038(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        cin >> str[i];
    sort(str,str+n,cmp0);
    string s;
    for(int i=0;i<n;++i)
        s+=str[i];
    while(s.size()>0 &&s[0]=='0')
//        s.erase(s.begin());
        s=s.substr(1);
    if(s.size()==0)
        cout << "0";   // Ponit2 "0\n" 格式错误
    cout << s <<"\n";
    return 0;
}
