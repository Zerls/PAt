//
// 1037.cpp 
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

int i1037(){
    int n,m,p=0,q=0,sum=0;
    scanf("%d",&n);
    vector<int> a(n);
    for (int i=0; i<n; ++i) 
        scanf("%d",&a[i]);
    scanf("%d",&m);
    vector<int> b(m);
    for (int i=0; i<m; ++i)
        scanf("%d",&b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (a[p]<0 && b[q]<0 && p<n && q<m) {
        sum+=a[p]*b[q];
        p++;
        q++;
    }
    p=n-1;
    q=m-1;
    while (a[p]>0 && b[q]>0 && p>=0 && q>=0) {
        sum+=a[p]*b[q];
        p--;
        q--;
    }
    printf("%d\n",sum);
    
    return 0;
}
