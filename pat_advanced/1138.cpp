//
// 1138.cpp 
// pat 
// 
// Created by zerl on 2019/1/11. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <vector>
#include <iostream>
using namespace std;
static vector<int> pre,in;
static bool flag=false;
static void postOrder(int prel,int inl,int inr){
    if(inl >inr ||flag==true) return;
    int i=inl ;//int i=0;
    while(pre[prel]!=in[i]) i++;
    postOrder(prel+1,inl,i-1);
    postOrder(prel+i-inl+1,i+1,inr);
    if(flag==false){
        printf("%d",in[i]);
        flag=true;
    }
}
int i1138(){
    int n;
    scanf("%d",&n);
    pre.resize(n);
    in.resize(n);
    for (int i=0; i<n; ++i) scanf("%d",&pre[i]);
    for (int i=0; i<n; ++i) scanf("%d",&in[i]);
    postOrder(0,0,n-1);
    printf("\n");
    return 0;
}
