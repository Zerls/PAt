//
// 1115.cpp 
// pat 
// 
// Created by zerl on 2019/1/14. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int d;
    struct Node *l,*r;
};
static vector<int> num(1000);
static int maxdepth=-1;
static Node* build(Node *root ,int d){
    if(root ==NULL){
        root =new Node();
        root->d=d;
        root->l=root->r=NULL;
    }else if(d<=root->d){
        root->l=build(root->l, d);
    }else{
        root->r=build(root->r, d);
    }
    return root;
}
static void dfs(Node * root,int depth){
    if(root ==NULL) {
        maxdepth=max(depth,maxdepth);
        return;
    }
    num[depth]++;
    dfs(root->l,depth+1);
    dfs(root->r,depth+1);
}

int i1115(){
    int n,temp;
    Node* root=NULL;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&temp);
        root=build(root, temp);
    }
    dfs(root,1);
    printf("%d + %d = %d",num[maxdepth-1],num[maxdepth-2],num[maxdepth-1]+num[maxdepth-2]);
    
    return 0;
}
