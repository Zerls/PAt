//
// 1104.cpp 
// pat 
// 
// Created by zerl on 2019/1/27. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
int main(){
    int n;
    double sum=0,temp;
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) {
        scanf("%lf",&temp);
        sum+=temp*i*(n-i+1);
    }
    printf("%.2lf",sum);
    return 0;
}