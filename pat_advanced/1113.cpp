//
// 1113.cpp 
// pat 
// 
// Created by zerl on 2019/1/23. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int i1113(){
    int n,num=0,halfsum=0;
    scanf("%d",&n);
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&v[i]);
        num+=v[i];
    }
    sort(v.begin(), v.end());
    for (int i=0; i<n/2; ++i) {
        halfsum+=v[i];
    }
    printf("%d %d\n",n%2,num-2*halfsum);
    return 0;
}
