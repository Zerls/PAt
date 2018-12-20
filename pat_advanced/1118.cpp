//
// 1118.cpp 
// pat 
// 
// Created by zerl on 2018/12/20. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
static int n, m, k;
static const int maxn = 10010;
static int fa[maxn] = {0}, cnt[maxn] = {0};
static int findFather(int x) {
    int a = x;
    while(x != fa[x])
        x = fa[x];
    while(a != fa[a]) {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}
static void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) fa[faA] = faB;
}
static bool exist[maxn];
int i1118() {
    scanf("%d", &n);
    for(int i = 1; i <= maxn; i++)
        fa[i] = i;
    int id, temp;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &k, &id);
        exist[id] = true;
        for(int j = 0; j < k-1; j++) {
            scanf("%d", &temp);
            Union(id, temp);
            exist[temp] = true;
        }
    }
    for(int i = 1; i <= maxn; i++) {
        if(exist[i] == true) {
            int root = findFather(i);
            cnt[root]++;
        }
    }
    int numTrees = 0, numBirds = 0;
    for(int i = 1; i <= maxn; i++) {
        if(exist[i] == true && cnt[i] != 0) {
            numTrees++;
            numBirds += cnt[i];
        }
    }
    printf("%d %d\n", numTrees, numBirds);
    scanf("%d", &m);
    int ida, idb;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &ida, &idb);
        printf("%s\n", (findFather(ida) == findFather(idb)) ? "Yes" : "No");
    }
    return 0;
}
