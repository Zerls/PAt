//
// 1111.cpp 
// pat 
// 
// Created by zerl on 2019/1/16. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static const int INF=0x3fffffff,N=510;
static int dis[N],Time[N],e[N][N],w[N][N],disPre[N],timePre[N],weight[N],nodeNum[N];
static bool visited[N];
static vector<int> disPath,timePath;
static int st,fin ,minnode=INF; //start finally
static void dfs_disPath(int v){
    disPath.push_back(v);
    if(v==st) return;
    dfs_disPath(disPre[v]);
}

static void dfs_timePath(int v){
    timePath.push_back(v);
    if(v==st) return;
    dfs_timePath(timePre[v]);
}
int i1111(){
    fill(dis, dis+N, INF);
    fill(e[0], e[0]+N*N, INF);
    fill(Time, Time+N, INF);
    fill(weight, weight+N, INF);
    fill(w[0], w[0]+N*N, INF);
    int n,m;
    scanf("%d %d",&n,&m);
    int a,b,flag,len,t;
    for (int i=0; i<m; ++i) {
        scanf("%d %d %d %d %d",&a,&b,&flag,&len,&t);
        e[a][b]=len;
        w[a][b]=t;
        if(flag !=1){
            e[b][a]=len;
            w[b][a]=t;
        }
    }
    scanf("%d %d",&st,&fin);
    
    dis[st]=0;
    weight[st]=0;
    for (int i=0; i<n; ++i) {
        int u=-1,minn=INF;
        for (int j=0; j<n; ++j) {
            if(visited[j] ==false &&  dis[j] < minn){
                u=j;
                minn=dis[j];
            }
        }
        if(u==-1) break;
        visited[u]=true;
        for (int v=0; v<n; ++v) {
            if (visited[v] ==false &&  e[u][v] != INF) {
                if(dis[v]>dis[u]+e[u][v]){
                    dis[v]=dis[u]+e[u][v];
                    disPre[v]=u;
                    weight[v]=weight[u]+w[u][v];
                }else if(dis[v]==dis[u]+e[u][v] && weight[v]>weight[u]+w[u][v]){
                    weight[v]=weight[u]+w[u][v];
                    disPre[v]=u;
                }
            }
        }
    }
    dfs_disPath(fin);
    
    Time[st]=0;
    fill(visited, visited+N, false);
    for (int i=0; i<n; ++i) {
        int u=-1,minn=INF;
        for (int j=0; j<n; ++j) {
            if(visited[j] ==false &&  Time[j] < minn){
                u=j;
                minn=Time[j];
            }
        }
        if(u==-1) break;
        visited[u]=true;
        for (int v=0; v<n; ++v) {
            if (visited[v] ==false &&  w[u][v] != INF) {
                if(Time[v]>Time[u]+w[u][v]){
                    Time[v]=Time[u]+w[u][v];
                    timePre[v]=u;
                    nodeNum[v]=nodeNum[u]+1;
                }else if(Time[v]==Time[u]+w[u][v] && nodeNum[v]>nodeNum[u]+1){
                    timePre[v]=u;
                    nodeNum[v]=nodeNum[u]+1;
                }
            }
        }
    }
    dfs_timePath(fin);
    printf("Distance = %d",dis[fin]);
    if(disPath==timePath){
        printf("; Time = %d: ",Time[fin]);
    }else{
        printf(": ");
        for (int i=disPath.size()-1; i>=0; --i) {
            printf("%d%s",disPath[i],(i!=0)? " -> ":"");
        }
        printf("\nTime = %d: ",Time[fin]);
    }
    for (int i=timePath.size()-1; i>=0; --i) {
        printf("%d%s",timePath[i],(i!=0) ?" -> ":"");
    }
    return 0;
}
