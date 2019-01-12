//
// 1052.cpp 
// pat 
// 
// Created by zerl on 2019/1/12. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int address, key, next;
    bool flag;
}node_1052[100000];
static int cmp1(Node a, Node b) {
    return (!a.flag || !b.flag ? a.flag >b.flag :a.key <b.key);
    //只要a 和b 中有一个无效元素。就把它放到后面去
}
int i1052() {
    int n,cnt=0,begin,a,b,c;
    scanf("%d%d",&n,&begin);
    for (int i=0; i<n; ++i) {
        scanf("%d%d%d",&a,&b,&c);
        node_1052[a]={a,b,c,false};
    }
    for(;begin !=-1;begin=node_1052[begin].next){
        node_1052[begin].flag=true;
        cnt++;
    }
    sort(node_1052, node_1052+100000, cmp1);
    if(cnt !=0){
        printf("%d %d\n",cnt,node_1052[0].address);
        for (int i=0; i<cnt-1; ++i)
            printf("%05d %d %05d\n",node_1052[i].address,node_1052[i].key,node_1052[i+1].address);
        printf("%d %d -1\n",node_1052[cnt-1].address,node_1052[cnt-1].key);
    }else
        printf("0 -1\n");
    return 0;
    
}
