//
// 1117.cpp 
// pat 
// 
// Created by zerl on 2019/1/11. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int i1117(){
    int n,e=0;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;++i)
        scanf("%d",&v[i]);
    sort(v.begin(),v.end(),greater<int>());
    while(e<n && v[e]>e+1) e++;
    printf("%d\n",e);
    return 0;
}
