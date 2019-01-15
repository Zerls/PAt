//
// 1039.cpp 
// pat 
// 
// Created by zerl on 2019/1/15. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
static const int maxn = 26 * 26 * 26 * 10 + 10;
static vector<int> v[maxn];
static unordered_map<string,int> m1;
static unordered_map<int,string> m2;
int i1039() {
    int n, k, no, num, id = 0;
    string name;
    name.resize(5);
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &no, &num);
        for(int j = 0; j < num; j++) {
            scanf("%s",&name[0]);
            if(!m1.count(name)){
                m1[name]=id;
                m2[id]=name;
                id++;
            }
            v[m1[name]].push_back(no);
        } }
    for(int i = 0; i < n; i++) {
        scanf("%s",&name[0]);
        if(!m1.count(name)){
            printf("%s 0\n",name.c_str());
        }else{
            id = m1[name];
            sort(v[id].begin(), v[id].end());
            printf("%s %lu",name.c_str(),v[id].size());
            for(int j = 0; j < v[id].size(); j++)
                printf(" %d", v[id][j]);
            printf("\n");
        }
    }
    return 0;
}
