//
// 1071.cpp 
// pat 
// 
// Created by zerl on 2019/1/15. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
//

#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int i1071(){
    string s,t;
    map<string,int> m;
    getline(cin, s);
    for (int i=0; i<s.length(); ++i) {
        if(isalnum(s[i])){
            s[i]=tolower(s[i]);
            t+=s[i];
        }
        if(!isalnum(s[i]) || i==s.size()-1){
            if(t.length() !=0) m[t]+=1; //   if(s.length() !=0) m[t]+=1;
            t="";
        }
    }
    int maxn = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second > maxn) {
            t = it->first;
            maxn = it->second;
        }
    }
    cout << t << " " << maxn;
    return 0;
}
