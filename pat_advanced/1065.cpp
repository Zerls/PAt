//
// 1065.cpp 
// pat 
// 
// Created by zerl on 2018/4/1. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <iostream>

int i1065() {
    freopen("1065.txt", "r",stdin);
    int t,i=0;
    long long a,b,c;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld%lld%lld",&a,&b,&c);
        long long sum = a+b;
        if(a > 0 && b > 0 && sum < 0)
            printf("Case #%d: true\n", ++i);
        else if(a < 0 && b < 0 && sum >= 0)
            printf("Case #%d: false\n", ++i);
        else if(sum > c)
            printf("Case #%d: true\n", ++i);
        else
            printf("Case #%d: false\n", ++i);
    }
    return 0;
}
