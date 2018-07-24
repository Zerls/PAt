//
// 1019.cpp 
// pat 
// 
// Created by zerl on 2018/7/18. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;

int i1019() {
    
    freopen("1019.txt","r",stdin);
    int a,b,index=0,flag=1;
    int ans[40];
    scanf("%d%d",&a,&b);
    
    while (a !=0 ) {
        ans[index++]= a % b;
        a=a/b;
        
    }
    
    for(int  i = 0; i < index/2; i++) {
        if (ans[i] != ans[index-1-i]) {
            printf("No\n");
            flag=0;
            break;
        }
    }
    
    if (flag)
        printf("Yes\n");
    
    for(int  i = index-1; i >= 0; i--) {
        printf("%d",ans[i]);
        if(i !=0 ) printf(" ");
    }
    if(index == 0)
        printf("0");
    
    return 0;
}
