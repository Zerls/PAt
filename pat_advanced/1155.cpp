//
// 1155.cpp 
// pat 
// 
// Created by zerl on 2018/12/18. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;

static vector<int> v;
static int a[1009],n,isMax=1,isMin=1;

static void dfs(int index){
//    if(index*2>n&&index*2+1>n){
    if(index*2>n){
        if(index<=n){
            for (int i=0; i<v.size(); ++i) {
                //for (int i=1; i<v.size(); ++i) {
                printf("%d%s",v[i],i !=v.size()-1 ?" ":"\n");
                //printf("%d%s",v[i],i v[i]=v.size()-1 ?" ":"\n");
            }
        }
    }else{
        v.push_back(a[index*2+1]);
        dfs(index*2+1);
        v.pop_back();
        v.push_back(a[index*2]);
        dfs(index*2);
        v.pop_back();
    }
}

int i1155(){
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) {
        scanf("%d",&a[i]);
    }
    v.push_back(a[1]);
    dfs(1);
    for (int i=2; i<=n; ++i) {
//        for (int i=1; i<=n; ++i) {
        if(a[i/2]<a[i]) isMax=0;
        if(a[i/2]>a[i]) isMin=0;
    }
    if(isMin==1){
        printf("Min Heap");
    }else{
//        isMax==1 ? printf("Max Heap"):printf("Not Heap");
        printf("%s", isMax == 1 ? "Max Heap" : "Not Heap");
    }
    return 0;
}
