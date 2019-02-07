//
// 1150.cpp 
// pat 
// 
// Created by zerl on 2019/2/07. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int e[205][205],nn,m,k,a,b,c,n,mindis=0x3fffffff,id=0;
int main(){
    scanf("%d %d",&nn,&m);
    for (int i=0; i<m; ++i) {
        scanf("%d %d %d",&a,&b,&c);
        e[a][b]=e[b][a]=c;
    }
    scanf("%d",&k);
    for (int i=1; i<=k; ++i) {
        int na=0,dis=0;
        scanf("%d",&n);
        vector<int> v(n);
        set<int> s;
        for (int j=0; j<n; ++j) {
            scanf("%d",&v[j]);
            s.insert(v[j]);
            if(j!=0 && e[v[j]][v[j-1]]<=0) na=1;
            if(j!=0) dis+=e[v[j]][v[j-1]];
        }
        if(na==1){
            printf("Path %d: NA (Not a TS cycle)\n",i);
        }else if(s.size()!=nn ||v[0]!=v[n-1] ){
            printf("Path %d: %d (Not a TS cycle)\n",i,dis);
        }else{
            if(mindis > dis){
                mindis=dis;
                id=i;
            }
            if( n-1==nn){
                printf("Path %d: %d (TS simple cycle)\n",i,dis);
            }else 
                printf("Path %d: %d (TS cycle)\n",i,dis);
        }
    }
    printf("Shortest Dist(%d) = %d\n",id,mindis);
    return 0;
}
