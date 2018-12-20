//
// 1050.cpp 
// pat 
// 
// Created by zerl on 2018/12/20. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <set>
using namespace std;
int i1050(){
    string s1,s2;
    set<char> s;
    getline(cin, s1);
    getline(cin,s2);

    for(int i=0;i<s2.size();++i)
        s.insert(s2[i]);
    for(int i=0;i<s1.size();++i){
        if(s.find(s1[i])==s.end()){
//            cout << s1[i] ;
            printf("%c", s1[i]);
        }
    }
    printf("\n");
    
    return 0;
}



