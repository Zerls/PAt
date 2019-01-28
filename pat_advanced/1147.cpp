//
// 1147.cpp 
// pat 
// 
// Created by zerl on 2019/1/13. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;
static int m,n;
static vector<int> v;
static void postOrder(int index){
    if(index >= n) return ;
    postOrder(index*2+1);
    postOrder(index*2+2);
    printf("%d%s",v[index],index ==0 ? "\n": " ");
}
int i1147(){
    scanf("%d%d",&m,&n);
    v.resize(n);
    while (m--) {
        for (int i=0; i<n; ++i) scanf("%d",&v[i]);
        int flag =(v[0]>v[1]) ? 1:-1;
        for (int i=0; i<=(n-1)/2; ++i) { // for (int i=0; i<(n-1)/2; ++i) {
            int l=i*2+1,r=i*2+2;
            if(flag==1 &&(v[i]<v[l]||(r<n && v[i]<v[r]))) flag=0;
            if(flag==-1 &&(v[i]>v[l]||(r<n && v[i]>v[r]))) flag=0;
        }
        if (flag==0) printf("Not Heap\n");
        else printf("%s Heap\n",flag == 1 ? "Max":"Min");
        postOrder(0);
    }
    return 0;
}
