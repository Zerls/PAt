//
// 1121.cpp 
// pat 
// 
// Created by zerl on 2019/1/19. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
//

#include <iostream>
#include <set>
#include <vector>
using namespace  std;
int i1121(){
    set<int> s,s1;
    vector<int> ma(100000,-1);
    int n,m,a,b;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d %d",&a,&b);
        ma[a]=b;
        ma[b]=a;
    }
    scanf("%d",&m);
    for (int i=0; i<m; ++i) {
        scanf("%d",&a);
        (ma[a]==-1) ? s1.insert(a): s.insert(a);
    }
    for (auto it=s.begin(); it !=s.end(); ++it)
        if(s.find(ma[*it]) ==s.end())
            s1.insert(*it);
    printf("%d\n",s1.size());
    for (auto it=s1.begin(); it !=s1.end(); ++it)
        printf("%s%05d",(it !=s1.begin())?" ":"",*it);
    return 0;
}
