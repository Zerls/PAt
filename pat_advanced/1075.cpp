//
// 1075.cpp 
// pat 
// 
// Created by zerl on 2019/1/23. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int rank,id,total_score,pass_num,isshown;
    vector<int> p;
};
static vector<node> v;
static bool cmp1(node &a,node &b){
    if(a.total_score !=b.total_score){
        return    a.total_score>b.total_score;
    }else {
        return a.pass_num!=b.pass_num ? a.pass_num> b.pass_num : a.id <b.id;}
}
int i1075(){
    int n,k,m,problem[6],tid,tp,tscore;
    scanf("%d%d%d",&n,&k,&m);
    v.resize(n+1);
    for (int i=1; i<=n; i++)
        v[i].p.resize(k+1,-1);
    for (int i=1; i<=k; i++)
        scanf("%d",&problem[i]);
    for (int i=0; i<m; ++i) {
        scanf("%d%d%d",&tid,&tp,&tscore);
        v[tid].id=tid;
        v[tid].p[tp]=max(v[tid].p[tp], tscore);
        if(tscore !=-1){
            v[tid].isshown=1;
        }else if (v[tid].p[tp] ==-1)
            v[tid].p[tp]=-2;;
        //        if(tscore !=-1 && v[tid].p[tp] < tscore){
        ////            v[tid].p[tp]=tscore;
        //
        //            v[tid].id=tid;
        //            v[tid].isshown=1;
        //        }else if(tscore ==-1 && v[tid].p[tp] == -1){
        //            v[tid].p[tp]=-2;
        //        }
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=k; ++j) {
            if(v[i].p[j]==problem[j]) v[i].pass_num++;
            if(v[i].p[j] !=-1 &&v[i].p[j] !=-2) v[i].total_score+=v[i].p[j];
        }
    }
    sort(v.begin()+1, v.end(), cmp1);
    for(int i = 1; i <= n; i++) {
        v[i].rank = i;
        if(i != 1 && v[i].total_score == v[i - 1].total_score)
            v[i].rank = v[i - 1].rank;
    }
    for (int i=1; i<=n; ++i) {
        if(v[i].isshown==1){
            printf("%d %05d %d",v[i].rank,v[i].id,v[i].total_score);
            for (int j=1; j<=k; ++j) {
                if (v[i].p[j] != -1 && v[i].p[j] != -2) printf(" %d", v[i].p[j]); //(v[i].p[j] !=-1 &&v[i].p[j] !=-2)
                else
                    printf(" %s",(v[i].p[j] == -1)? "-" : "0");
            }
            printf("\n");
        }
    }
    return 0;
}
