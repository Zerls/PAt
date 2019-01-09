//
// 1087.cpp 
// pat 
// 
// Created by zerl on 2019/1/8. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


static int n,k;
static const int N=205,inf=0x3fffffff;
static int e[N][N],weight[N],dis[N];
static bool visit[N];//
static int maxvalue,cntpath;
static double maxavg;
static vector<int> temppath,path,pre[N];//pre[N]
static map<string,int> m;
static map<int,string> m2;

static void dfs(int v){
    temppath.push_back(v);
    if(v==1){
        int value=0;
        for (int i =temppath.size()-1; i>=0; i--) {
            value += weight[temppath[i]];
        }
        double tempavg= 1.0*value/(temppath.size()-1);
        if(value>maxvalue){
            maxvalue=value;
            maxavg=tempavg;
            path=temppath;
        }else if(value==maxvalue && tempavg > maxavg){
            maxavg=tempavg;
            path=temppath;
        }
        temppath.pop_back();
        cntpath++;
        return;
    }
    for (int i=0; i<pre[v].size(); ++i) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int i1087() {
    fill(dis,dis+205,inf);
    fill(e[0],e[0]+205*205,inf);
    string s1;
    cin >> n >> k >> s1;
    m[s1]=1;
    m2[1]=s1;
    for (int i=1; i<n; ++i) {
        cin >> s1 >> weight[i+1];
        m[s1]=i+1;
        m2[i+1]=s1;
    }
//    string sa,sb;
//    for (int i=0; i<k; ++i) {
//        cin >> sa >> sb >> e[m[sa]][m[sb]];
//        e[m[sb]][m[sa]]=e[m[sa]][m[sb]];
//    }
    string sa, sb;
    int temp;
    for(int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]] = temp;
        e[m[sb]][m[sa]] = temp;
    }
    dis[1]=0;
    for (int i=0; i<n; i++) {
        int u=-1,minu=inf;
        for (int j=1; j<=n; ++j) { //P
            if(visit[j]==false&& dis[j]<minu){
                u=j;
                minu=dis[j];
            }
        }
        if(u==-1) break;
        visit[u]=true;
        for (int v=1; v<=n; ++v) {
            if(visit[v]==false&& e[u][v]!=inf){ //P
                if(dis[v]>dis[u]+e[u][v]){
                dis[v]=dis[u]+e[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }else if(dis[v]==dis[u]+e[u][v]){
                pre[v].push_back(u);
            }
        }
        }
    }
  
    int rom=m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n",cntpath,dis[rom],maxvalue,(int)maxavg);
    for (int i=path.size()-1; i>=1; --i) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM\n";
    return 0;
}
