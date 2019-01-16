//
// 1079.cpp 
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
struct Node{
    double data;
    vector<int> child;
};
static vector<Node> v;
static double ans=0.0,p,r;
static void dfs(int root,int depth){
    if(v[root].child.size()==0){
        ans += v[root].data*pow(1+r,depth);//ans = 1+pow(r,depth);
        return;
    }
    for (int i=0; i<v[root].child.size(); ++i) {
        dfs(v[root].child[i],depth+1);
    }
}

int i1079(){
    int n,k,t;
    scanf("%d %lf %lf",&n,&p,&r);
    r=r/100;
    v.resize(n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&k);
        if(k==0){
             scanf("%lf",&v[i].data);
        }else{
            for (int j=0; j<k; ++j) {
                scanf("%d",&t);
                v[i].child.push_back(t);
            }
        }
    }
    dfs(0,0);
    printf("%.1f\n",ans*p);// printf("%.1f\n",ans);
    return 0;
}
