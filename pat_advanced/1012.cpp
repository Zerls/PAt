//
// 1012.cpp 
// pat 
// 
// Created by zerl on 2018/10/31. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct node_0 {
    int id,best;
    int score[4],rank[4];
} stu[2005];
map<int,int> exist;
int flag = -1 ;
bool cmp1(node_0 a,node_0 b){return a.score[flag] > b.score[flag];}

int i1012() {
    int n, m, id;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i ) {
        scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0;
    }
    for (flag =0; flag<4; ++flag) {
        sort(stu, stu+n, cmp1);
        stu[0].rank[flag]=1;
        for (int i=1; i<n; ++i) {
            stu[i].rank[flag]=i+1;
            if (stu[i-1].score[flag]==stu[i].score[flag])
                stu[i].rank[flag]=stu[i-1].rank[flag];
        }
    }
    for (int i = 0; i < n; ++i) {
        exist[stu[i].id]=i+1;
        stu[i].best=0;
        int minn=stu[i].rank[0];
        for (int j =1; j<4; ++j) {
            if(minn>stu[i].rank[j]){
                minn=stu[i].rank[j];
                stu[i].best=j;
            }
        }
    }
    char c[]={'A','C','M','E'};
    for (int i =0; i < m; ++i) {
        scanf("%d",&id);
        int temp=exist[id];
        if(temp){
            int best=stu[temp-1].best;
            printf("%d %c\n",stu[temp-1].rank[best],c[best]);
        }else
            printf("N/A\n");
    }
    return 0;
}


//P? i j 混乱  rank score 混乱 ，读清题！
