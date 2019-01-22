//
// 1028.cpp 
// pat 
// 
// Created by zerl on 2019/1/21. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node_1028{
    int id,score;
    string name;
};
static int n,c;
static vector<node_1028> v;
//看清题目比较条件
static bool cmp1(node_1028 &a,node_1028 &b){
    if(c==1){
        return  a.id <b.id;
    }else if(c==2){
        return (a.name !=b.name) ? a.name <b.name: a.id <b.id ;
    }else
        return (a.score !=b.score) ? a.score <b.score: a.id <b.id ;
}
//static bool cmp1(node_1028 &a,node_1028 &b){
//    if(c==1){
//        return  a.id <b.id;
//    }else
//        return (c==2) ? a.name <=b.name: a.score <=b.score ; // return (c==2) ? a.name <b.name: a.score <b.score ;
//}
int i1028(){
    scanf("%d%d",&n,&c);
    v.resize(n);
    for (int i=0; i<n; ++i)
        cin >> v[i].id >> v[i].name >> v[i].score;
    sort(v.begin(), v.end(), cmp1);
    for (int i=0; i<n; ++i)
        printf("%06d %s %d\n",v[i].id,v[i].name.c_str(),v[i].score);
    return 0;
}
