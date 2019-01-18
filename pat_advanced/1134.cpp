//
// 1134.cpp 
// pat 
// 
// Created by zerl on 2019/1/18. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;

int i1134(){
    int n,m,a,b,k,nv;
    scanf("%d %d",&n,&m);
    vector< vector<int> > v(n);
for (int i=0; i<m; ++i) {//    for (int i=0; i<n; ++i) {
        scanf("%d %d",&a,&b);
        v[a].push_back(i);//
        v[b].push_back(i);//
    }
    scanf("%d",&k);
    for (int i=0; i<k; ++i) {
        vector<int> have(m,0);
        int flag=0;
        scanf("%d",&nv);
        for (int j =0; j<nv; ++j) {
            scanf("%d",&a);
            for (int k=0; k<v[a].size(); ++k) {
                have[v[a][k]]=1;
            }
        }
        for (int j=0; j<m; ++j) {
            if(have[j] ==0){
                printf("No\n");
                flag=1;
                break;
            }
        }
        if(flag==0) printf("Yes\n");
    }
    return 0;
}
