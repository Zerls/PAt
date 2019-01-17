//
// 1131.cpp 
// pat 
// 
// Created by zerl on 2019/1/17. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
static vector<vector<int>> v(10000);
static unordered_map<int, int> line;
static int minTransfer,minCnt,visit[10000],start,end1;
static vector<int> path,tempPath;
static int tranferCnt(vector<int> & path){
    int cnt=-1,preline=0;
    for (int i=1; i<path.size(); ++i) {
        if(line[(path[i-1])*10000+path[i]] != preline)    cnt++;
        preline=line[(path[i-1])*10000+path[i]];
    }
    return cnt;
}
static void dfs(int node,int cnt) {
    if(node == end1){
        if(minCnt > cnt||(minCnt ==cnt && minTransfer >tranferCnt(tempPath) )){
            minCnt = cnt;
            minTransfer =tranferCnt(tempPath) ;
            path=tempPath;
        }
        return ;
    }

    for (int i=0; i<v[node].size(); ++i) {
        if(visit[v[node][i]]==0){
            visit[v[node][i]]=1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt+1);
            tempPath.pop_back();
            visit[v[node][i]]=0;
        }
    }
}
int i1131(){
    int n,m,pre,temp,k;
    scanf("%d",&n);
    for (int i = 0; i<n; ++i) {
        scanf("%d %d",&m,&pre);
        for (int j=1; j < m; ++j) {//for (int j=0; j < m; ++j) {
            scanf("%d",&temp);
            v[temp].push_back(pre);
            v[pre].push_back(temp);
            line[pre*10000+temp]=line[temp*10000+pre]=i+1;//line[pre*10000+temp]=1;
            pre=temp;
        }
    }
    scanf("%d",&k);
    for (int i=0; i<k; ++i) {
        scanf("%d %d",&start,&end1);
        minTransfer=0x3fffffff,minCnt=0x3fffffff;
        tempPath.clear();
        tempPath.push_back(start);
        //        tempPath.clear();
        //        tempPath.push_back(start);
        visit[start]=1;
        dfs(start,0);
        visit[start]=0;
        printf("%d\n",minCnt);
        int preTransfer=start,preLine=line[path[0]*10000+path[1]];
       for (int j=1; j< path.size(); ++j) { //for (int j=1; j< path.size()-1; ++j) {
            if (line[path[j-1]*10000+path[j]] != preLine) {
              //  if(preLine !=0) printf("Take Line#%d from %04d to %04d.\n",preLine,preTransfer,path[j]);
                //if(preLine !=0) printf("Take Line#%d from %04d to %04d.\n",preLine,preTransfer,path[j-1]);
                printf("Take Line#%d from %04d to %04d.\n",preLine,preTransfer,path[j-1]);
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer=path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",preLine,preTransfer,end1);
    }
    return 0;
}

