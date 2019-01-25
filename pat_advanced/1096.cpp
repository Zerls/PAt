//
// 1096.cpp 
// pat 
// 
// Created by zerl on 2019/1/25. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <stdio.h>
#include <cmath>
using namespace std;

int i1096(){
    int n,temp,len=0,maxn,first=0;
    scanf("%d",&n);
    maxn=sqrt(n);
    for (int i=2; i<=maxn; ++i) {
        int j;temp=1;
        for (j=i; j<=maxn; ++j) {
            temp*=j;
            if(n%temp !=0) break;
        }
        if(j-i>len){
            len=j-i;
            first=i;
        }
    }
    if(first==0) printf("1\n%d",n);
    else{
        printf("%d\n",len);
        for (int i=0; i<len; ++i) {
            printf("%d%s",first+i,(i!=len-1)?"*":"\n");
        }
    }
        
    return 0;
}
