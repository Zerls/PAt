//
// 1109.cpp 
// pat 
// 
// Created by zerl on 2019/1/22. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    string name;
    int h;
};
static bool cmp1(node &a,node &b){
    return a.h !=b.h ? a.h>b.h: a.name <b.name;
}
int i1109(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<node> v(n);
    for (int i=0; i<n; ++i) {
        v[i].name.resize(9);
        scanf("%s %d",&v[i].name[0],&v[i].h);
    }
    sort(v.begin(), v.end(), cmp1);
    int t=0,row=k,m;
    while (row) {
        if(row==k){
            m=n/k+n%k;
//            m=n-n/k*(k-1);
        }else{
            m=n/k;
        }
        vector<string> ans(m);
        ans[m/2]=v[t].name;
        int j= m/2-1;
        for (int i=t+1; i<t+m; i+=2) {
            ans[j--]=v[i].name;
        }
        j= m/2+1;
        for (int i=t+2; i<t+m; i+=2) {
            ans[j++]=v[i].name;
        }
        for (int i=0; i<m; i++)
            printf("%s%s",ans[i].c_str(),(i!=m-1)?" ":"\n");
        t+=m;
        row--;//换行
    }
    return 0;
}
//模拟题完整模拟一遍过程，了解过程
