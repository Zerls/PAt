//
// 1009.cpp 
// pat 
// 
// Created by zerl on 2018/4/10. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <stdio.h>

int i1009() {
    freopen("1009.txt","r",stdin);
    int k1,k2,num=0,exp;
    double ans[2001]={0.0},poly[1001]={0.0},coe;
    
    scanf("%d",&k1);
    for (int i =0; i < k1; ++i){
        scanf("%d%lf",&exp,&coe);
        poly[exp]=coe;
    }
    
    scanf("%d",&k2);
    for (int i =0; i < k2; ++i) {
        scanf("%d%lf",&exp,&coe);
        for (int j=0; j < k1; ++j)
            ans[exp+j] += coe * poly[j];
    }
    
    for (int i =0 ; i <= 2000; ++i)
        if (ans[i] !=0.0) num++;
    printf("%d",num);
    
    for (int i = 2000; i>= 0; i--)
        if (ans[i] !=0.0) printf(" %d %.1f",i,ans[i]);
    
    return 0;
}
