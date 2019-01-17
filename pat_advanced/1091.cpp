//
// 1091.cpp 
// pat 
// 
// Created by zerl on 2019/1/17. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

//
#include <cstdio>
#include <queue>
using namespace std;
struct Node{
    int x,y,z;
};
static int  n,m,l,t;
static int X[6]={1,0,0,-1,0,0};
static int Y[6]={0,1,0,0,-1,0};
static int Z[6]={0,0,1,0,0,-1};
static bool visited[1300][130][80];
static int slices[1300][130][80];
static bool judge(int x,int y,int z){
    if(x<0 ||y<0 || z<0 ||x>=m || y>=n || z>= l) return false;
    if(visited[x][y][z] ==true || slices[x][y][z] ==0 ) return false;
    return  true;
}
static int bfs(int i ,int j,int k){
    int tx,ty,tz,cnt=0;
    queue<Node> q;
    q.push(Node{i,j,k});
    visited[i][j][k]=true;
    while (!q.empty()) {
        Node top =q.front();
        q.pop();
        cnt+=1;
        for (int i=0; i<6; ++i) {
            tx=top.x+X[i];
            ty=top.y+Y[i];
            tz=top.z+Z[i];
            if (judge(tx,ty,tz)) {
                q.push(Node{tx,ty,tz});
                visited[tx][ty][tz] =true;
            //    cnt+=1;
            }
        }
    }
    if(cnt >=t) return cnt;
    else
    return 0;
}


int i1091(){
    
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int k = 0; k < l; k++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &slices[i][j][k]);
            }}}
    int ans = 0;
    for(int k = 0; k < l; k++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(slices[i][j][k] == 1 && visited[i][j][k] == false)
                    ans += bfs(i, j, k);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
