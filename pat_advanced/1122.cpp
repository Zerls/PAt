//
// 1122.cpp 
// pat 
// 
// Created by zerl on 2019/1/10. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int i1122(){
    int N,n,m,k,e[205][205]={0};
    cin >> N >> m;
    for (int i=0 ; i<m; ++i) {
        int a,b;
        cin >> a >> b;
        e[a][b]=e[b][a]=1; // e[b][a]=1
    }
//    cin >> k;
//    for (int i=0; i<k; ++i) {
//        int flag1=1,flag2=1;
//        cin >> n;
//        vector<int> v(n);
//        set<int> s;
//        for (int j=0; j<n; ++j) {
//            cin >> v[j];
//            s.insert(v[j]);
//        }
//        if(s.size()!=N || n-1 !=N || v[0]!=v[n-1]) flag1=0;
//        for (int j=0; j<n-1; ++j)
//            if(e[v[j]][v[j+1]]==0) flag2=0;
//        cout << ((flag1 && flag2) ?"YES":"NO")  <<"\n"; // P ||-> &&
//    }
    
    cin >> k;
    while(k--){
        int flag1=1,flag2=1;
        cin >> n;
        vector<int> v(n);
        set<int> s;
        for (int i=0; i<n; ++i) {
            cin >> v[i];
            s.insert(v[i]);
        }
        if(s.size()!=N || n-1 !=N || v[0]!=v[n-1]) flag1=0;
        for (int i=0; i<n-1; ++i)
            if(e[v[i]][v[i+1]]==0) flag2=0; // ++ break;
        cout << ((flag1 && flag2) ?"YES":"NO")  <<"\n"; // P ||-> &&
    }
    return 0;
}
