//
// 1110.cpp 
// pat 
// 
// Created by zerl on 2019/1/14. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;

struct Node{
    int l,r;
}node_1110[100];
static int maxn=-1,ans;

static void dfs(int root,int index){
    if(index > maxn){
        maxn=index;
        ans=root;
    }
    if(node_1110[root].l !=- 1) dfs(node_1110[root].l,index*2); //
    if(node_1110[root].r !=- 1) dfs(node_1110[root].r,index*2+1); //
}
int i1110(){
    int n,root=0,exited[100]={0};
    cin >> n;
    for (int i=0; i<n; ++i) {
        string l,r;
        cin >> l >> r;
        if(l=="-"){
            node_1110[i].l=-1;
        }else{
            node_1110[i].l=stoi(l);
            exited[stoi(l)]=1;
        }
        if(r=="-"){
            node_1110[i].r=-1;
        }else{
            node_1110[i].r=stoi(r);
            exited[stoi(r)]=1;
        }
    }
    while (exited[root] !=0) root++;
    dfs(root,1); // maxn 计数
    printf("%s %d\n",maxn == n ?"YES":"NO",maxn == n ? ans : root); //
    return 0;
}




//static void dfs(int root,int index){
//    if(index > maxn){
//        maxn=index;
//        ans=root;
//    }
//    if(node_1110[root].l !=- 1) dfs(node_1110[root].l,index*2+1); //
//    if(node_1110[root].r !=- 1) dfs(node_1110[root].r,index*2+2); //
//}
//int i1110(){
//    int n,root=0,exited[100]={0};
//    cin >> n;
//    for (int i=0; i<n; ++i) {
//        string l,r;
//        cin >> l >> r;
//        if(l=="-"){
//            node_1110[i].l=-1;
//        }else{
//            node_1110[i].l=stoi(l);
//            exited[stoi(l)]=1;
//        }
//        if(r=="-"){
//            node_1110[i].r=-1;
//        }else{
//            node_1110[i].r=stoi(r);
//            exited[stoi(r)]=1;
//        }
//    }
//    while (exited[root] !=0) root++;
//    dfs(root,0); //
//    printf("%s %d\n",maxn+1 == n ?"YES":"NO",maxn+1 == n ? ans : root); //
//    return 0;
//}
