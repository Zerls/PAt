//
// 1030.cpp 
// pat 
// 
// Created by zerl on 2019/1/2. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int INF=0x3fffffff;
static bool visit[510];
static int dis[510],e[510][510],cost[510][510],mincost=INF;
static int n,m,s,d;
static vector<int> path,temppath;
static vector<int> pre[510];

static void DFS(int v){
    temppath.push_back(v);
    if(v==s){
        int tempcost=0;
        for (int i=temppath.size()-1; i>0; --i) {
            int id=temppath[i],nextid=temppath[i-1]; //边权更新
            tempcost +=cost[id][nextid];
        }
        if(tempcost<mincost){
            mincost=tempcost;
            path=temppath;  //P?
        }
        temppath.pop_back();
        return;
    }
    for (int i=0; i<pre[v].size(); ++i) {
        DFS(pre[v][i]);
    }
    temppath.pop_back();
}

int i1030(){
    fill(dis,dis+510,INF);
    fill(e[0],e[0]+510*510,INF);
    scanf("%d %d %d %d",&n,&m,&s,&d);
    for (int i=0; i<m; ++i) {
        int a=0,b=0;
        scanf("%d %d",&a,&b);
        scanf("%d %d",&e[a][b],&cost[a][b]);
        e[b][a]=e[a][b];
        cost[b][a]=cost[a][b];
    }
//    pre[s].push_back(s);
    dis[s]=0;
    for (int i=0; i<n; ++i) {
        int u=-1 ,min=INF;
        for (int j=0; j<n; ++j) {
            if(visit[j]==false&& dis[j]<min){  //P : dis[j] !=INF
                u=j;
                min=dis[j];
            }
        }
        if(u==-1) break;
        visit[u]=true;
        for (int v=0; v<n; ++v) {
            if(visit[v]==false&& e[u][v]!=INF){
                if(dis[v]>dis[u]+e[u][v]){  //P : dis[v]+e[u][v])
                    dis[v]=dis[u]+e[u][v];  //P : dis[v]+e[u][v])
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v]==dis[u]+e[u][v]){ //P : dis[v]+e[u][v])
                    pre[v].push_back(u);
                }
            }
        }
    }
    DFS(d);
    for (int i=path.size()-1; i>=0; --i) {
        printf("%d ",path[i]);
        
    }
    printf("%d %d\n",dis[d],mincost);
    
    return 0;
}
