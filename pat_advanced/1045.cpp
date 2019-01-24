//
// 1045.cpp 
// pat 
// 
// Created by zerl on 2019/1/24. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static int book[201], a[10001], dp[10001];

int i1045(){
    int n,m,l,x,maxn=0,num=0;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=m; ++i) {
        scanf("%d",&x);
        book[x]=i;
    }
    scanf("%d",&l);
    for (int i=0; i<l; ++i) {
        scanf("%d",&x);
        if(book[x]>=1){
            a[num++]=book[x];
        }
    }
    for (int i=0; i<num; ++i) {
        dp[i]=1;
        for (int j=0; j<i; ++j) {
            if(a[i]>=a[j]){//if(a[j]>a[i]){ 最长不下降子序列
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxn=max(maxn,dp[i]);
    }
    printf("%d\n",maxn);
    return 0;
}
