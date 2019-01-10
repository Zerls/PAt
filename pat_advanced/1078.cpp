//
// 1078.cpp 
// pat 
// 
// Created by zerl on 2019/1/10. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static bool isPrime(int a){
    if(a <=1) return false;
    int sqr =int(sqrt(1.0*a));
    for (int i=2; i<=sqr; ++i)
        if(a %i ==0) return false;
    return true;
}
int i1078(){
    int msize,n;
    scanf("%d%d",&msize,&n);
    while (!isPrime(msize)) msize++;
    vector<int> v(msize);
    for (int i=0; i<n; ++i) {
        int temp,flag=1;
        scanf("%d",&temp);
        for (int j=0; j<=msize; ++j) {
            int p=(temp+j*j)%msize;
            if(v[p]==0){
                v[p]=temp;
                flag=0;
                printf("%d",p);
                break;
            }
        }
        if(flag==1)printf("-");
        if(i !=n-1) printf(" ");
        if(i ==n-1) printf("\n");
    }
    return 0;
}
