//
// 1043.cpp 
// pat 
// 
// Created by zerl on 2019/1/14. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;
static vector<int> pre,post;
static bool isMirror=false;
static void getPost(int root,int tail){
    if(root > tail) return;
    int i=root+1,j=tail;
    if(!isMirror){
        while (i <= tail && pre[root] > pre[i]) i++; //while (i < tail && pre[root] <pre[i]) i++;
        while (j > root && pre[root] <= pre[j]) j--;
    }else{
        while (i <= tail && pre[root] <=pre[i]) i++;
        while (j > root && pre[root] > pre[j]) j--;
    }
    if(i-j != 1) return ;
    getPost(root+1, j);
    getPost(i, tail);
    post.push_back(pre[root]);
}
int i1043(){
    int n;
    scanf("%d",&n);
    pre.resize(n);
    for (int i=0; i<n; ++i) scanf("%d",&pre[i]);
    getPost(0,n-1);
    if(post.size() != n){
        isMirror=true;
        post.clear();
        getPost(0, n-1);
    }
    if(post.size() == n){
        printf("YES\n%d",post[0]);
        for (int i=1; i<n; ++i) {
            printf(" %d",post[i]);
        }
    }else
        printf("NO");
    printf("\n");
    return 0;
}

//int i1043() {
//    int n;
//    scanf("%d", &n);
//    pre.resize(n);
//    for(int i = 0; i < n; i++)
//        scanf("%d", &pre[i]);
//    getPost(0, n - 1);
//    if(post.size() != n) {
//        isMirror = true;
//        post.clear();
//        getPost(0, n - 1);
//    }
//    if(post.size() == n) {
//        printf("YES\n%d", post[0]);
//        for(int i = 1; i < n; i++)
//            printf(" %d", post[i]);
//    } else {
//        printf("NO");
//    }
//    return 0;}
