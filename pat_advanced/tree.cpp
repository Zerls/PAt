//
// tree.cpp 
// pat 
// 
// Created by zerl on 2018/7/23. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <cstdio>
using namespace std;
int post[] = {3, 4, 2, 6, 5, 1};
int in[] = {3, 2, 4, 1, 6, 5};
void pre(int root, int start, int end) {
    if (start > end ) return;
    int i =start;
    while(i < end && post[root] !=in[i]) i++;
    printf("%d ",in[i]);
    pre(root-(end-i)-1, start, i-1);
    pre(root-1, i+1, end);
}

int tree() {
    pre(5, 0, 5);
    return 0;
}
