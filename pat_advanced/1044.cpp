//
// 1044.cpp 
// pat 
// 
// Created by zerl on 2019/1/20. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 
#include <iostream>
#include <vector>
using namespace std;
static vector<int> sum,resultArr;
static int n,m;
static void fn(int i,int &j ,int &tempsum){
    int l=i,r=n;
    while (l <r) {
        int  mid =(l+r)/2;
        if(sum[mid]-sum[i-1] >=m)
            r=mid;
        else
            l=mid+1;
    }
    j=r;
    tempsum=sum[j]-sum[i-1];
}

int i1044(){
    scanf("%d%d",&n,&m);
    sum.resize(n+1);
    for (int i=1; i<=n; ++i) {
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
    }
    int mincost=sum[n];
    for (int i=1; i<=n; ++i) {
        int j,tempsum;
        fn(i,j,tempsum);
        if(tempsum > mincost) continue; //
        if(tempsum>=m){
            if(tempsum <mincost){
                resultArr.clear();
                mincost=tempsum;
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
        
    }
    for (int i=0; i<resultArr.size(); i+=2)
        printf("%d-%d\n",resultArr[i],resultArr[i+1]);
    return 0;
}
