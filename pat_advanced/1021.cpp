//
// 1021.cpp 
// pat 
// 
// Created by zerl on 2018/12/16. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

static int n,maxheight;//
static vector<vector<int>> v;
static bool visited[10010];
static set<int> s;
static vector<int> temp;

static void dfs(int node,int deepth){
    visited[node]=true;
    if(deepth>maxheight){
        temp.clear();
        temp.push_back(node);
        maxheight=deepth;//P 更新最大深度

    }else if (maxheight==deepth){//P 当前深度==最大深度 -> 加入节点集合
        temp.push_back(node);
    }

    for (int i=0; i<v[node].size(); ++i) {
        if (visited[v[node][i]]==false)//遍历未访问节点
            dfs(v[node][i],deepth+1);
    }
}

int i1021(){
    scanf("%d",&n);
    v.resize(n+1);//~  邻接表初始化  1~N 0~N->(n+1)
    int a,b,cnt=0,s1=0;
    for (int i=0; i<n-1; ++i) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=1; i<=n; ++i) { // topic：nodes are numbered from 1 to N.
        if (visited[i] ==false){//遍历未访问节点
            dfs(i, 1);
            if(i==1){
                if(temp.size() != 0) s1=temp[0];
                for (int j=0; j<temp.size(); ++j)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }

    if(cnt>=2){
        printf("Error: %d components",cnt);
    }else{
        temp.clear();//  初始化temp
//        maxheight=0;//初始化
        fill(visited, visited+10010, false);// 初始化

        dfs(s1,1); //assert s1 had init
        for (int i=0; i<temp.size(); ++i)
            s.insert(temp[i]);
        for (auto it=s.begin(); it!=s.end(); ++it)
            printf("%d\n",*it);
    }
    return 0;
}


//两次dfs遍历



/* vector temp -> set temp 测试点4
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

static int n,maxheight;//
static vector<vector<int>> v;
static bool visited[10010];
static set<int> s;
static vector<int> temp;

static void dfs(int node,int deepth){
    
    visited[node]=true;
    if(deepth>maxheight){
        s.clear();
        s.insert(node);
        maxheight=deepth;//P 更新最大深度
        
    }else if (maxheight==deepth){//P 当前深度==最大深度 -> 加入节点集合
        s.insert(node);
    }
    
    for (int i=0; i<v[node].size(); ++i) {
        if (visited[v[node][i]]==false)//遍历未访问节点
            dfs(v[node][i],deepth+1);
    }
}

int i1021(){
    scanf("%d",&n);
    v.resize(n+1);//~  邻接表初始化  1~N 0~N->(n+1)
    int a,b,cnt=0,s1=0;
    for (int i=0; i<n-1; ++i) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=1; i<=n; ++i) { // topic：nodes are numbered from 1 to N.
        if (visited[i] ==false){//遍历未访问节点
            dfs(i, 1);
            if(i==1){
                if(s.size() != 0) s1=*s.begin();
            }
            cnt++;
        }
    }
    
    if(cnt>=2){
        printf("Error: %d components",cnt);
    }else{
        //temp.clear();//  初始化temp
        //        maxheight=0;//初始化
        fill(visited, visited+10010, false);// 初始化
        
        dfs(s1,1); //assert s1 had init
//        for (int i=0; i<temp.size(); ++i)
//            s.insert(temp[i]);
        s.insert(s1);
        for (auto it=s.begin(); it!=s.end(); ++it){

            printf("%d\n",*it);
        }
    
    }
    return 0;
}


//两次dfs遍历
 */

