//
// 1004.cpp 
// pat 
// 
// Created by zerl on 2018/10/19. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxdepth = -1;
vector<int> vs[100],record(100);
void dfs(int index,int depth){
    if (vs[index].size() == 0) {
        record[depth]+=1;
        maxdepth=max(depth, maxdepth);
        return;
    }
    for (int i=0; i<vs[index].size(); ++i) {
        dfs(vs[index][i], depth+1);
    }
    return;
}

int i1004(){
    int n,m,id,k,c;
    scanf("%d %d",&n,&m);
    for (int i=0; i < m; ++i) {
        scanf("%d%d",&id,&k);
        for (int j=0 ; j< k ; ++j) {
            scanf("%d",&c);
            vs[id].push_back(c);
        }
    }
    dfs(1,0);
    for (int i=0; i <=maxdepth; ++i) {
        if(i!=0) printf(" ");
        printf("%d",record[i]);
    }
    printf("\n");
    return 0;
}
