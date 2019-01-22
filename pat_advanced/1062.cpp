//
// 1062.cpp 
// pat 
// 
// Created by zerl on 2019/1/21. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node_1062{
    int id,de,zhi;
};
static int n,l,h,tid,tde,tzhi;
static vector< vector<node_1062> > v(4);

static bool cmp1(node_1062 &a,node_1062 &b){
    if(a.de+a.zhi !=b.de+b.zhi){
        return a.de+a.zhi >b.de+b.zhi;
    }else
        return a.de != b.de ? a.de >b.de:a.id <b.id;
}
int i1062(){
    scanf("%d %d %d",&n,&l,&h);
    for (int i=0; i<n; ++i) {
        scanf("%d %d %d",&tid,&tde,&tzhi);
        if(tzhi <l || tde <l) continue;
        if(tde >=h && tzhi >=h){
            v[0].push_back(node_1062{tid,tde,tzhi});
        }else if( tzhi <h && tde >=h){
            v[1].push_back(node_1062{tid,tde,tzhi});
        }else if( tzhi <h && tde <h && tde >=tzhi){
            v[2].push_back(node_1062{tid,tde,tzhi});
        }else  {
            v[3].push_back(node_1062{tid,tde,tzhi});
        }
    }
    for (int i=0; i<4; ++i)
        sort(v[i].begin(), v[i].end(), cmp1);
    printf("%d\n",int(v[0].size()+v[1].size()+v[2].size()+v[3].size()));
    for (int i=0; i<4; ++i) {
        for (int j=0; j<v[i].size(); ++j)
            printf("%08d %d %d\n",v[i][j].id,v[i][j].de,v[i][j].zhi);
    }
    return 0;
}
//分类建立数组；分解 复杂性
