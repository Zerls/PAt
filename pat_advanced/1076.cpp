//
// 1076.cpp 
// pat 
// 
// Created by zerl on 2019/1/9. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
static int n, l, m, k;
struct node_1076{
    int id,layer;
};

static vector<vector<int>> v;

static int bfs(node_1076 & tnode){
    int cnt =0;
    bool visit[1010]={false};
    queue<node_1076> q;
    q.push(tnode);
    visit[tnode.id]=true;
    while(!q.empty()){
        node_1076 top=q.front();
        q.pop();
        int topid=top.id;
        for (int i=0; i<v[topid].size(); ++i) {
             int nextid=v[topid][i];
            if(visit[nextid] ==false && top.layer <l){
                node_1076 next={nextid,top.layer+1};
                visit[nextid] =true;
                q.push(next);
                cnt++;
            }
        }
    }
    
    return cnt;
}
int i1076() {
    scanf("%d %d",&n,&l);
    v.resize(n+1);
    for (int i=1; i<=n; ++i) {
        scanf("%d",&m);
        for (int j=0; j<m; ++j) {
            int temp;
            scanf("%d",&temp);
            v[temp].push_back(i);
        }
    }
    scanf("%d",&k);
    int tid;
    for (int i=0; i<k; ++i) {
        scanf("%d",&tid);
        node_1076 tnode={tid,0};
        printf("%d\n",bfs(tnode));
    }
    return 0;
}
