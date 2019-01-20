//
// 1085.cpp 
// pat 
// 
// Created by zerl on 2019/1/20. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int i1085(){
    int n,p;
    scanf("%d%d",&n,&p);
    vector<long long> v(n);
    for (int i=0; i<n; ++i)
        scanf("%lld",&v[i]);
    sort(v.begin(), v.end());
    int i=0,j=0,len=0;;
    while(j<n) {
        if(v[j] <=v[i]*p){
            len=max(len,j-i+1);
             j++;
        }else
            i++;
    }
    printf("%d\n",len);
    return 0;
}
