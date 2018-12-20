//
// 1054.cpp 
// pat 
// 
// Created by zerl on 2018/12/20. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <map>
#include <iostream>
using namespace std;

static map<int,int> flag;
int i1054(){
    int n,m,a;
    scanf("%d %d",&n,&m);
    n=n*m;
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        flag[a]++;
    }
    int max=-1;
    for(auto it=flag.begin();it!=flag.end();++it)
        if(it->second>flag[max]) max=it->first;
    
    cout << max <<"\n";
    return 0;
}


int i1054_2(){
    int n,m,a;
    scanf("%d %d",&n,&m);
    n=n*m;
    int half =n/2;
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        flag[a]++;
        if(flag[a]>half){
            cout << a <<"\n";
            return 0;
        }
    }
    return 0;
}
