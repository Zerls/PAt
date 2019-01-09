//
// 1072.cpp 
// pat 
// 
// Created by zerl on 2019/1/8. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 
//-------
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

static  const int inf = 0x3fffffff;
static  int n, m, k, ds;
static  int e[1020][1020], dis[1020];
static bool visit[1020];

static void dijkstra(int index){
    fill(dis, dis + 1020, inf);
    fill(visit, visit + 1020, false);
    dis[index] = 0;
    
    
    for(int i = 0; i < n + m; i++) {
        int u = -1, minn = inf;
        for(int j = 1; j <= n + m; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n + m; v++) {
            if(visit[v] == false && e[u][v] !=inf){
            if( dis[v] > dis[u] + e[u][v])
                dis[v] = dis[u] + e[u][v];
        }
        }
    }
}

int i1072() {
    fill(e[0], e[0] + 1020 * 1020, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    
    for(int i = 0; i < k; i++) {
        int tempdis;
        string s, t;
        cin >> s >> t >> tempdis;
        int a, b;
        if(s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a = stoi(s); }
        if(t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b] = e[b][a] = tempdis;
    }
    
    int ansid = -1; //ansid 存放最终加油站 id
    double ansdis = -1, ansaver = inf; //ansdis 存放使最大的最短距离，ansaver 存放最小平均距离
    
    for(int index = n + 1; index <= n + m; index++) {
        
        double mindis = inf, aver = 0; //mindis 为最大的最近距离，aver 为平均距离
        
        dijkstra(index);
        
        for(int i = 1; i <= n; i++) {
            if(dis[i] > ds) {
                mindis = -1;
                break;
            }
            if(dis[i] < mindis) mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if(mindis == -1) continue;
        aver = aver / n;
        if(mindis > ansdis) {
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if(mindis == ansdis && aver < ansaver) {
            ansid = index;
            ansaver = aver;
        }
        
    }
    
    
    if(ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f\n", ansid - n, ansdis, ansaver);
    return 0;
}
