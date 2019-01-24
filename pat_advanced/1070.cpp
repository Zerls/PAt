//
// 1070.cpp 
// pat 
// 
// Created by zerl on 2019/1/24. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node_1070{
    // int ton;  double/int 有损失， 带小数的要定义为浮点型
    double ton,yuan,price;
};
static bool cmp1(node_1070 &a,node_1070 &b){
    return a.price > b.price;
}
int i1070(){
    int n,d;
    double ans=0.0;
    scanf("%d %d",&n,&d);
    vector<node_1070> v(n);
    for (int i=0; i<n; ++i) {
        scanf("%lf",&v[i].ton);
    }
    for (int i=0; i<n; ++i) {
        scanf("%lf",&v[i].yuan);
        v[i].price=1.0*v[i].yuan/v[i].ton;
    }
    sort(v.begin(), v.end(), cmp1);
    for (int i=0; i<n; ++i) {
        if(v[i].ton <=d){
            ans+=v[i].yuan;
        }else{
            ans+=v[i].price*d;
            break;
        }
        d-=v[i].ton;
    }
    printf("%.2lf\n",ans);
    return 0;
}
