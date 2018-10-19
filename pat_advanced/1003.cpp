//
// 1003.cpp 
// pat 
// 
// Created by zerl on 2018/10/18. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <iostream>
#include <algorithm>
using namespace std;

//#define N 510
const int N=510;
const int INF=0x3fffffff;
int n,m,c1,c2;
int e[N][N],diss[N],w[N],weight[N],num[N];
bool visit[N];

void input(bool test,string str){
    if(test){
        freopen(str.c_str(),"r",stdin);
        printf("==test==\n");
    }
    fill(diss,diss+N,INF);
    fill(e[0],e[0]+N*N,INF); //知识点 二维数组填充
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    for(int i = 0;i < n;i++)
        scanf("%d",&weight[i]);

    int a,b,c;
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&a,&b,&c);
        e[a][b]=e[b][a]=c;
    }

}

void dijkstra1(){
    diss[c1]=0;
    w[c1]=weight[c1];
    num[c1]=1;
    
    for(int i=0;i<n;i++){
        int u=-1,minu=INF;
        for(int j=0;j<n;j++){ //?? 索引j->i错写
            if(visit[j] == false && diss[j]<minu){
                u=j;
                minu=diss[j];
            }
        }
        if(u == -1) break;
        visit[u]=true;
        for(int v=0;v<n;v++){
            if(visit[v] == false && e[u][v]!=INF){
                if(diss[u]+e[u][v]<diss[v]){
                    diss[v]=diss[u]+e[u][v];
                    num[v]=num[u];
                    w[v]=w[u]+weight[v]; //?? 遗忘更新权重
                }else if (diss[u]+e[u][v]==diss[v]){
                    if(w[v]<w[u]+weight[v])
                        w[v]=w[u]+weight[v];
                    num[v]+=num[u];
                }
            }
        }
    }
    printf("%d %d",num[c2],w[c2]);
}

int i1003(){
    input(1,"1003.txt");
    dijkstra1();
    return 0;
}
