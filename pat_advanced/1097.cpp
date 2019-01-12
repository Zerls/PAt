//
// 1097.cpp 
// pat 
// 
// Created by zerl on 2019/1/12. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
//

#include <iostream>
#include <algorithm>
using namespace std;
static const int maxn=100000;
struct Node{
    int addr,key,next,num=2*maxn;
}node[maxn];
static bool exited[maxn];
static bool cmp1(Node a,Node b){
    return a.num < b.num;
}
int i1097(){
    int begin,n,ta,cnt1=0,cnt2=0;
    scanf("%d%d",&begin,&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&ta);
        scanf("%d %d",&node[ta].key,&node[ta].next);
        node[ta].addr =ta;
    }
    for (; begin != -1; begin=node[begin].next) {
        if(exited[abs(node[begin].key)] ==false){
            exited[abs(node[begin].key)]=true;
            node[begin].num=cnt1;
            cnt1++;
        }else{
            node[begin].num=maxn+cnt2;
            cnt2++;
        }
    }
    sort(node, node+maxn, cmp1);
    int cnt=cnt1+cnt2;
    for (int i=0; i<cnt; ++i) {
        if(i!=cnt1-1 && i!=cnt-1){ // if(i!=cnt1-1 || i!=cnt-1)
            printf("%05d %d %05d\n",node[i].addr,node[i].key,node[i+1].addr);
        }else{
            printf("%05d %d -1\n",node[i].addr,node[i].key);
        }
    }
    return 0;
}
