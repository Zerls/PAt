//
// 1063.cpp 
// pat 
// 
// Created by zerl on 2019/1/18. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int i1063(){
    int n,m,k,temp,a,b;
    scanf("%d",&n);
    vector<set<int>> v(n+1);
    for (int i=1; i<=n; ++i) {
        scanf("%d",&m);
        set<int> s;
        for (int j=0; j<m; ++j) {
            scanf("%d",&temp);
            s.insert(temp);
        }
        v[i]=s; //v.push_back(s);   v->1~n
    }
    scanf("%d",&k);
    for (int i=0; i<k; ++i) {
        scanf("%d%d",&a,&b);
        int nc=0,nt=(int)v[b].size();
        for (auto it=v[a].begin(); it !=v[a].end(); ++it) {
            if (v[b].find(*it) ==v[b].end())
                nt++;
            else
                nc++;
        }
        printf("%.1f%%\n",(double)nc/nt*100);
    }
    return 0;
}
