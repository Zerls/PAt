//
// 1064.cpp 
// pat 
// 
// Created by zerl on 2019/1/14. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> in, level;
static int n,indexs=0;
static void inlorder(int level_root) {
    if(level_root > n) return ;

    inlorder(level_root*2);
    level[level_root] =in[indexs++];
    inlorder(level_root*2+1);
}
int i1064() {
    scanf("%d", &n);
    in.resize(n);
    level.resize(n+1);
    for(int i = 0 ; i < n; i++)
        scanf("%d", &in[i]);
    sort(in.begin(), in.end());
    inlorder(1);
    for(int i = 1; i <= n; i++)
        printf("%d%s", level[i],i!=n?" ":"\n");
    return 0;
}
