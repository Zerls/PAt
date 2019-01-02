//
// 1118.cpp 
// pat 
// 
// Created by zerl on 2018/12/20. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
static const int maxn=10010;
static int father[maxn],cnt[maxn];
static bool exist[maxn];
static int findFather(int x){
    int a=x;
    while (x !=father[x])
        x =father[x];
    while (a !=father[a]){
        int z=a;
        a = father[a];
        father[z]=x;
    }
    return x;
}

static void Union(int a, int b){
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA!=faB) father[faA]=faB;
}

int i1118(){
    int n;
    scanf("%d",&n);
    for (int i=1; i<=maxn; ++i)
        //P: for (int i=1; i<=n; ++i)
        father[i]=i;

    for (int i=0; i<n; ++i) {
        int k,tid,temp;
        scanf("%d %d",&k,&tid);
        exist[tid]=true;
        for (int j=0; j<k-1; ++j) {
        // for (int j=1; j<k; ++j) {
            scanf("%d",&temp);
            Union(tid,temp);
            exist[temp]=true;
        }
    }

    for (int i=1; i<=maxn; ++i) { //P: numbered continuously from 1 to some number that is no more than 104.
        if(exist[i]==true)
            cnt[findFather(i)]++;
    }
    int numTrees=0,numBirds=0;
    for (int i=1; i<=maxn; ++i) {
        if(exist[i]==true && cnt[i] !=0){ //P:
            numTrees++;
            numBirds +=cnt[i];
        }
    }
    printf("%d %d\n",numTrees,numBirds);
    
    int a,b,q;
    scanf("%d",&q);
    for (int i=0; i<q; ++i) {
        scanf("%d %d",&a,&b);
        printf("%s\n",findFather(a)==findFather(b) ? "Yes":"No");
    }
    return 0;
}
