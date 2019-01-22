//
// 1059.cpp 
// pat 
// 
// Created by zerl on 2019/1/22. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;
static vector<int> prime(500000,1);
int i1059(){
    long int a;
    scanf("%ld",&a);
    for (int i=2; i<500000; ++i) {
        for (int j=2; i*j<500000; ++j) {
            prime[i*j]=0;
        }
    }
    printf("%ld=",a);
    if(a==1)  printf("%ld",a);
    bool state=false;
    for (int i=2; a>1; ++i) {  //for (int i=2; a>2; ++i) { //97532468/4/11/17/101/1291=1
        int cnt=0,flag=0;
        while (prime[i]==1 && a%i==0) {
            cnt++;
            a=a/i;
            flag=1;
        }
        if(flag){
            if(state) printf("*");
            printf("%d",i);
            state=true;
        }
        if(cnt>=2)
            printf("^%d",cnt);
    }
    printf("\n");
    return 0;
}

