//
// 1103.cpp 
// pat 
// 
// Created by zerl on 2019/1/14. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static int n, k, p, maxFacSum = -1;
static vector<int> v, ans, tempAns;

static void init(){
    int temp=0,index=1;
    while(temp <= n){
        v.push_back(temp);
        temp=pow(index, p);
        index++;
    }
}
static void dfs(int index, int tempSum, int tempK, int facSum) {
    if(tempK ==k ){
        if(tempSum==n && facSum >maxFacSum){// if(tempSum > maxFacSum && tempAns>ans){
            maxFacSum =facSum;
            ans=tempAns;
        }
        return ;
    }
    for(;index >=1;--index){
        if(tempSum+v[index] <=n){
            tempAns[tempK]=index;
            dfs(index, tempSum+v[index], tempK+1, facSum+index);
        }
    }
}
int i1103() {
    scanf("%d %d %d",&n,&k,&p);
    init();
    tempAns.resize(k);
    dfs(v.size()-1,0,0,0);
    if(maxFacSum == -1){
        printf("Impossible");
        return 0;
    }
    printf("%d = ",n);
    for (int i=0; i<k; ++i) {
        printf("%s%d^%d" ,i!=0?" + ":"",ans[i],p);
    }
    return 0;
}
