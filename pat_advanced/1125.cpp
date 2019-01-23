//
// 1125.cpp 
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
int i1125(){
    int n;
    double num=0;
    scanf("%d",&n);
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&v[i]);
    }
    sort(v.begin(), v.end());
    num=(v[1]+v[0])/2;
    for (int i=2; i<n; i+=1) {
        num= (1.0*v[i]+num)/2;
    }
    printf("%d\n",(int)num);
    return 0;
}
