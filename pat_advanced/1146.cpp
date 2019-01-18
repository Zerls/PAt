//
// 1146.cpp 
// pat 
// 
// Created by zerl on 2019/1/18. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;

int i1146(){
    int n,m,k,a,b,c,flag=0;
    scanf("%d%d",&n,&m);
    vector<int> in(n+1);
    vector<vector<int> > v(n+1);
    for (int i=0; i<m; ++i) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        in[b]++;// in[a]++;//入度计数
    }
    scanf("%d",&k);
    for (int i=0; i<k; ++i) {
        int judge=1;
        vector<int> tin(in);
        for (int j=0; j<n; ++j) {
            scanf("%d",&c);
            if(tin[c] !=0) judge=0;
            for(int it : v[c]) tin[it]--;
        }
        if(judge==1) continue;
        printf("%s%d",(flag==0)?"":" ",i);
        flag=1;
    }
    return 0;
}
