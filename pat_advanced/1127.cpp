//
// 1127.cpp 
// pat 
// 
// Created by zerl on 2019/1/11. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static int n,root,tree[35][2];
static vector<int> result[35],in,post;
struct node{
    int index,depth;
};
static void dfs(int &index, int inLeft, int inRight, int postLeft, int postRight) { //△△△
    if(inLeft > inRight) return;
    int i=0;
    index =postRight;
    while(in[i]!=post[postRight]) i++;
    dfs(tree[index][0], inLeft, i-1, postLeft, postLeft+(i-inLeft)-1);
    dfs(tree[index][1], i+1, inRight, postLeft+(i-inLeft), postRight-1);
}
static void bfs() {
    queue<node> q;
    q.push(node{root,0});
    while (!q.empty()) {
        node t =q.front();
        q.pop();
        result[t.depth].push_back(post[t.index]); // result[t.depth].push_back(t.index);
        if(tree[t.index][0] !=0) q.push(node{tree[t.index][0],t.depth+1});
        if(tree[t.index][1] !=0) q.push(node{tree[t.index][1],t.depth+1});
    }
}
int i1127() {
    cin >> n;
    in.resize(n+1);
    post.resize(n+1);
    for (int i=1; i<=n; ++i) cin >> in[i];
    for (int i=1; i<=n; ++i) cin >> post[i];
    dfs(root,1,n,1,n);
    bfs();
    printf("%d",result[0][0]);
    for (int i=1; i<35; ++i) {
        if( i %2==1)
            for (int j=0; j<result[i].size(); ++j)
                printf(" %d",result[i][j]);
        else
            for (int j=result[i].size()-1; j>=0; --j)
                printf(" %d",result[i][j]);
    }
    printf("\n");
    return 0;
}
