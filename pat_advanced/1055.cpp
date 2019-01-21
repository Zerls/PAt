//
// 1055.cpp 
// pat 
// 
// Created by zerl on 2019/1/21. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node_1055{
    string name;
    int age,net_north;
};
static bool cmp1(node_1055 &a,node_1055 &b){
    if(a.net_north != b.net_north){
        return a.net_north > b.net_north;
    }else
        return   a.age != b.age ? a.age <b.age : a.name <b.name; //  a.age != b.age ? a.age <b.age : a.name <=b.name;
}
static vector<node_1055> vt,v,fin;
static vector<int> book(205,0);
int i1055(){
    int n,k,m,min_age,max_age;
    scanf("%d%d",&n,&k);
    vt.resize(n);
    for (int i=0; i<n; ++i) {
        vt[i].name.resize(9);
        scanf("%s %d %d",&vt[i].name[0],&vt[i].age,&vt[i].net_north);
    }
    sort(vt.begin(),vt.end(),cmp1);
    for (int i=0; i<n; ++i) {
        if(book[vt[i].age] < 100) { //剪枝
            v.push_back(vt[i]);
            book[vt[i].age]++;
        }
    }
    for (int i=1; i<=k; ++i) {
        fin.clear();
        scanf("%d %d %d",&m,&min_age,&max_age);
        printf("Case #%d:\n",i);
        for (int j=0; j<v.size() &&fin.size()<=m; ++j) { //fin.size()<=m  剪枝
            if(v[j].age >= min_age && v[j].age <= max_age)
                fin.push_back(v[j]);
        }
        for (int j=0; j<m && j<fin.size(); ++j)
            printf("%s %d %d\n",fin[j].name.c_str(),fin[j].age,fin[j].net_north);
        if (!fin.size()) printf("None\n");
    }
    return 0;
}

//n,m左右数据相差过大，不建议新开数组


