//
// 1090.cpp 
// pat 
// 
// Created by zerl on 2019/1/16. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static vector<int> v[100005];
static int maxNum,maxDepth;
static void dfs(int index ,int depth){
//    if(maxDepth<depth){
//        maxDepth=depth;
//        maxNum=1;
//    }else if(depth==maxDepth){
//        maxNum+=1;
//    }
    if(v[index].size()==0){
        if(maxDepth<depth){
            maxDepth=depth;
            maxNum=1;
        }else if(depth==maxDepth){
            maxNum+=1;
        }
        return;
    }
    for (int i=0; i<v[index].size(); ++i)
        dfs(v[index][i], depth+1);
}
int i1090(){
    int n,root=0,t;
    double p,r;
    scanf("%d%lf%lf",&n,&p,&r);
    for (int i=0; i<n; ++i) {
        scanf("%d",&t);
        if(t!=-1)
            v[t].push_back(i);
        else
            root=i;
    }
    dfs(root,0);
    printf("%.2lf %d\n",p*pow(r/100+1,maxDepth),maxNum);
    return 0;
}
