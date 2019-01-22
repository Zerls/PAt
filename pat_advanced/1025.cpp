//
// 1025.cpp 
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
struct node_1025 {
    long long int id;
    int fin_rank,loca_num,loca_rank,score;
};
static bool cmp1(node_1025 &a,node_1025 &b){
    return a.score != b.score ? a.score>b.score: a.id < b.id;
}
static vector<node_1025> v,fin;
int i1025(){
    int n,k,ts;
    long long int tid;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&k);
        v.clear();
        for (int j=0; j<k; ++j) {
            scanf("%lld%d",&tid,&ts);
            v.push_back(node_1025{tid,-1,i+1,-1,ts});
        }
        sort(v.begin(), v.end(), cmp1);
        v[0].loca_rank=1;
        fin.push_back(v[0]);
        for (int j=1; j<v.size(); ++j) {
            v[j].score==v[j-1].score ?  v[j].loca_rank=v[j-1].loca_rank:v[j].loca_rank=j+1;
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(), fin.end(), cmp1);
    printf("%d\n",(int)fin.size());
    fin[0].fin_rank=1;
    printf("%013lld %d %d %d\n",fin[0].id,fin[0].fin_rank,fin[0].loca_num,fin[0].loca_rank);
    for (int i=1; i<fin.size(); ++i) {
        fin[i].score==fin[i-1].score ? fin[i].fin_rank=fin[i-1].fin_rank:fin[i].fin_rank=i+1;
        printf("%013lld %d %d %d\n",fin[i].id,fin[i].fin_rank,fin[i].loca_num,fin[i].loca_rank);
    }
    return 0;
}
/**
 分步 先考场排序，再全排序  简化编程；
 **/
