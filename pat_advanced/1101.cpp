//
// 1101.cpp 
// pat 
// 
// Created by zerl on 2018/10/18. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <iostream>
#include <algorithm>
using namespace std;


int i1101(){
    int N;
    scanf("%d",&N);
    int numa[N],numb[N],numv[N];
    for (int i = 0; i < N; ++i) {
        int a;
        scanf("%d",&a);
        numa[i]=numb[i]=a;
    }
    
    sort(numa, numa+N);
    
    int count=0,min=0x3fffffff;//max=0
//    for (int i = 0; i < N; ++i) {
//        if(numa[i]==numb[i] && numb[i]>max){
//            numv[count++]=numb[i];
//        }
//        if(numb[i]>max){
//            max=numb[i];
//        }
//    }
    for (int i = N-1; i >= 0; --i) {
        if(numa[i]==numb[i] && numb[i]<min){
            numv[count++]=numb[i];
        }
        if(numb[i]<min){
            min=numb[i];
        }
    }
    printf("%d\n",count);
//    for (int i = 0; i < count; ++i) {
//        //输出方法：There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.
//        if(i!=0) printf(" ");
//        printf("%d",numv[i]);
//    }
    for (int i =  count-1; i >= 0; --i) {
        if(i!=count-1) printf(" ");
        printf("%d",numv[i]);
    }
    printf("\n");
    return 0;
}
