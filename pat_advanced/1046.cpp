//
// 1046.cpp 
// pat 
// 
// Created by zerl on 2018/3/28. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <algorithm>
using namespace std;

const int MAXN =100005;
int dis[MAXN];

int i1046() {
    freopen("1046.txt", "r", stdin);
    int sum=0,N,M,l,r;
    scanf("%d",&N);
    for (int i =1; i <= N; ++i) {
        int temp;
        scanf("%d",&temp);
        sum += temp;
        dis[i] =sum;
    }
    scanf("%d",&M);
    for (int i =0; i < M; ++i) {
        scanf("%d%d",&l,&r);
        if(l > r) swap(l, r);
        int temp = dis[r-1] -dis[l-1];
        printf("%d\n",min(temp,sum-temp));
    }
    
    return 0;
}
