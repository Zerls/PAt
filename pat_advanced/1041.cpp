//
// 1041.cpp 
// pat 
// 
// Created by zerl on 2018/12/18. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <stdio.h>
static int a[10001],m[10000];
int i1041(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    for (int i=0; i<n; ++i) {
        if(m[a[i]]==1){
            printf("%d\n",a[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}
