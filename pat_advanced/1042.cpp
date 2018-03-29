//
// 1042.cpp 
// pat 
// 
// Created by zerl on 2018/3/28. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <iostream>

const int N = 54;
const char mp[] = {'S','H','C','D','J'};

int i1042() {
    freopen("1042.txt", "r", stdin);
    int start[N+1],next[N+1],end[N+1];
    int K;
    scanf("%d",&K);
    for (int i =1 ; i <= N; ++i)  start[i]=i;
    for(int i = 1; i <= N; ++i) scanf("%d", &next[i]);
    
    for (int k =1; k <=K; ++k) {
        for (int i =1; i <=N; ++i) end[next[i]] = start[i];
        for (int i =1; i <=N; ++i) start[i]=end[i];
    }
    
    for(int i = 1; i <= N; i++) {
        if(i != 1) printf(" ");
        start[i]--;
        printf("%c%d", mp[start[i] / 13] , start[i] % 13 + 1);
    }

    return 0;
}
