//
// 1013.cpp 
// pat 
// 
// Created by zerl on 2018/12/11. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>

using namespace std;
static int v[1010][1010];
static bool visited[1010];
static int n;

void dfs(int node){
    visited[node]=true;
    for(int i=0;i<=n;++i){
        if(visited[i]==false && v[node][i]==1){
            dfs(i);
        }
    }
}

int i1013(){
    int m,k,a,b;
    scanf("%d%d%d",&n,&m,&k);
    
    for (int i=0; i<m; ++i) {
        scanf("%d%d",&a,&b);
        v[a][b]=v[b][a]=1;
    }
    
    for(int i=0;i<k;++i){
        fill(visited, visited+n+1, false); //初始化遍历
//        fill(visit, visit + 1010, false);
        scanf("%d",&a);
        int cnt =0;
        visited[a]=true; //标记为已经访问过=去除这个城市结点
        for (int j=1; j<=n; ++j) {
        // The cities are numbered from 1 to N.   so, inital j=1
            if(visited[j] == false){
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n",cnt - 1);
    }
    return 0;
}


/*
 边界条件：The cities are numbered from 1 to N
 P:
 fill(visited, visited+n, false);
 for (int j=1; j<n; ++j)
 R:
 fill(visited, visited+n+1, false);
  朴素->  fill(visit, visit + 1010, false);
 for (int j=1; j<=n; ++j)
 
 */
