//
// 1032.cpp 
// pat 
// 
// Created by zerl on 2019/1/12. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <cstdio>
using namespace std;
struct Node{
    char key;
    int next;
    bool flag;
}node_1032[100000];
int i1032(){
    int begin1,begin2,n,a,c;
    char b;
    scanf("%d%d%d",&begin1,&begin2,&n);
    for (int i=0; i<n; ++i) {
        scanf("%d %c %d",&a,&b,&c); //
        node_1032[a]={b,c,false};
    }
    for (; begin1 !=-1; begin1=node_1032[begin1].next)
        node_1032[begin1].flag=true;
    for (; begin2 !=-1; begin2=node_1032[begin2].next)
        if(node_1032[begin2].flag==true){
            printf("%05d\n",begin2);
            return 0;
        }
    printf("-1\n");
    return 0;
}
