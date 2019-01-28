//
// 1094.cpp 
// pat 
// 
// Created by zerl on 2019/1/17. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;
static int num[110],maxLevel=1,maxGen=0;
static vector<vector<int>> v;
static void dfs(int index ,int level){
    num[level]++;
    if(maxGen < num[level]) {
        maxLevel = level;
        maxGen = num[level];
    }
    for (int i=0; i<v[index].size(); ++i)
        dfs(v[index][i], level+1);
}
int i1094(){
    int n,m,k,id,temp;
    scanf("%d%d",&n,&m);
    v.resize(n+1);
    for (int i=0; i<m; ++i) {
        scanf("%d%d",&id,&k);
        for (int j=0; j<k; ++j) {
            scanf("%d",&temp);
            v[id].push_back(temp);
        }
    }
    dfs(1,1);
    printf("%d %d\n",maxGen,maxLevel);
    return 0;
}
