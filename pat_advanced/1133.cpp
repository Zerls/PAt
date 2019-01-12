//
// 1133.cpp 
// pat 
// 
// Created by zerl on 2019/1/12. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 
#include <iostream>
#include <vector>
using namespace std;
struct node{
    int addr,data,next;
};
int i1133(){
    int begin,n,k,ta,td,tn;
    node a[100010];
    scanf("%d%d%d",&begin,&n,&k);
    vector<node> ans,v;
    for (int i=0; i<n; ++i) {
        scanf("%d%d%d",&ta,&td,&tn);
        a[ta] = {ta,td,tn};
    }
    for (; begin !=-1; begin=a[begin].next) //for (; v0[begin].next !=-1; begin=v0[begin].next)
        v.push_back(a[begin]);
    for (int i=0; i<v.size(); ++i)
        if (v[i].data <0)  ans.push_back(v[i]);
    for (int i=0; i<v.size(); ++i)
        if (v[i].data >=0 && v[i].data <=k)  ans.push_back(v[i]);
    for (int i=0; i<v.size(); ++i)
        if (v[i].data >k)  ans.push_back(v[i]);
    for (int i=0; i<ans.size()-1; ++i)
        printf("%05d %d %05d\n",ans[i].addr,ans[i].data,ans[i+1].addr);
    printf("%05d %d -1\n",ans[ans.size()-1].addr,ans[ans.size()-1].data);
    return 0;
}

