//
// 1102.cpp 
// pat 
// 
// Created by zerl on 2019/1/17. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node_0{
    int id,l,r,index,level;
};
static vector<node_0> v,v1,v2;
static void dfs(int root,int index,int level){
    if(v[root].r !=-1) dfs(v[root].r,index*2+2,level+1);
    v1.push_back({root,0,0,index,level});
   if(v[root].l !=-1)  dfs(v[root].l,index*2+1,level+1);
}
static bool cmp1(node_0 a,node_0 b){
    if(a.level != b.level)  return a.level < b.level;
    return a.index > b.index; // return a.index < b.index;
}
int i1102(){
    int n,root=0,have[100]={0};
    string a,b;
    scanf("%d",&n);
    v.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> a >>b ;
        if(a !="-"){
            v[i].l=stoi(a);
            have[stoi(a)]=1;
        }else
            v[i].l=-1;
        if(b !="-"){
            v[i].r=stoi(b);
            have[stoi(b)]=1;
        }else
            v[i].r=-1;
    }
    while (have[root]==1) root++;
    dfs(root,0, 0);
    v2=v1;
    sort(v2.begin(),v2.end(),cmp1);
    for (int i=0; i<n; ++i)
        printf("%d%s",v2[i].id,(i!=n-1)? " ":"\n");
    for (int i=0; i<n; ++i)
        printf("%d%s",v1[i].id,(i!=n-1)? " ":"\n");
    return 0;
}
