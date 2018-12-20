//
// 1107.cpp 
// pat 
// 
// Created by zerl on 2018/12/19. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> father, isRoot;
static int cmp1(int a, int b){return a > b;}
static int findFather(int x) {
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}


static int findFather_1(int v){
    int a=v;
    while(v!=father[v]){
        v=father[v];
    }
    while (a != father[a]) { //路径压缩
        int z=a;
        a=father[a];
        father[z]=v;
//        father[z]=a;
    }
    return v;
}

static int findFather_2(int v){
    if(v==father[v]) return v;
    else{
//        int F=findFather(v);
        int F =findFather_2(father[v]);
        father[v]=F;
        return F;
    }
}

static void Union_1(int a,int b){
    int faA =findFather(a);
    int faB =findFather(b);
    if(faA != faB) father[faA] = faB;
//    faA>faB ? father[faA]=faB;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;
}


int i1107(){
    int n,k,h,hi[1001]={0},cnt=0;;
    scanf("%d",&n);
    father.resize(n+1);
    isRoot.resize(n+1);
    for (int i=1; i<father.size(); ++i) // :O
//    for (int i=1; i<=n; ++i)
        father[i]=i;  //初始化
    for (int i=1; i<=n; ++i) {
        scanf("%d:",&k);
        for (int j=0; j<k; ++j) {
            scanf("%d",&h);
            if(hi[h]==0)
                hi[h]=i;
            Union(i, findFather(hi[h]));
        }
    }
    for (int i=1; i<=n; ++i)
        isRoot[findFather(i)]++;
    
    for (int i=1; i<=n; ++i)
        if(isRoot[i]!=0) cnt++;
    
    printf("%d\n",cnt);
    sort(isRoot.begin(),isRoot.end(),cmp1);
    for (int i=0; i<cnt; ++i) {
        //    for (int i=0; i<isRoot.size(); ++i) {
        printf("%d",isRoot[i]);
        if(i!=cnt-1) printf(" ");
//        if(i!=isRoot.size()-1) printf(" ");
    }
    
    return 0;
}

