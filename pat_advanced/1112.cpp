//
// 1112.cpp 
// pat 
// 
// Created by zerl on 2019/1/28. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <set>
#include <map>
using namespace std;
bool unStuck[256];
int main(){
    int k,cnt=1;
    string s;
    map<char,bool> ma;
    set<char> se;
    cin >> k >> s;
    char pre='#';
    for (int i=0; i<s.size(); ++i) {
        if(pre==s[i]){
            cnt++;
        }else{
            if(cnt%k !=0){
                unStuck[pre]=true;
            }
            cnt=1;
        }
        if(pre!=s.size()-1 && cnt %k ==0) ma[pre]=true;
        pre=s[i];
    }
    for (int i=0; i<s.size(); ++i) {
        if(ma[s[i]]&& unStuck[s[i]]==false &&se.find(s[i])==se.end()){
            printf("%c",s[i]);
            se.insert(s[i]);
        }
    }
    cout<<"\n";
    for (int i=0; i<s.size(); ++i) {
        printf("%c",s[i]);
        if(se.find(s[i])!=se.end())
            i=i+k-1;
    }
    cout <<"\n";
    return 0;
}