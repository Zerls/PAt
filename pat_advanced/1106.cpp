//
// 1106.cpp 
// pat 
// 
// Created by zerl on 2019/1/16. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
static vector<int> v[100010];
static int lowest=0x3fffffff,num,n,k,temp;
static void dfs(int index,int depth){
    if(lowest < depth) return; //剪枝
    if(v[index].size()==0){
        if(lowest >depth){
            lowest =depth;
            num=1;
        }else if(lowest == depth)
            num+=1;
        return;
    }
    for (int i=0; i<v[index].size(); ++i)
        dfs(v[index][i], depth+1);
}
int i1106(){
    double p,r;
    scanf("%d %lf %lf",&n,&p,&r);
    for (int i=0; i<n; ++i) {
        scanf("%d",&k);
        for (int j=0; j<k; ++j) {
            scanf("%d",&temp);
            v[i].push_back(temp);
        }
    }
    dfs(0,0);
    printf("%.4lf %d\n",p*pow(1+r/100,lowest),num);
    return 0;
}
