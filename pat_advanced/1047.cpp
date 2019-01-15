//
// 1047.cpp 
// pat 
// 
// Created by zerl on 2019/1/15. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
static vector<string> courses[2505];
int i1047(){
    int n,k,temp,a;
    string name;
    name.resize(5);
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; ++i) {
        scanf("%s %d",&name[0],&temp);
        for (int j=0; j<temp; ++j) {
            scanf("%d",&a);
            courses[a].push_back(name);
        }
    }
    for (int i=1; i<=k; ++i) {
        printf("%d %d\n",i,(int)courses[i].size());
        sort(courses[i].begin(),courses[i].end());
        for (int j=0; j<courses[i].size(); ++j) {
            printf("%s\n",courses[i][j].c_str());
        }
    }
    return 0;
}
