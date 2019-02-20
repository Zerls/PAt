//
// 1152.cpp 
// pat 
// 
// Created by zerl on 2019/2/18. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int a){
    if(a<=1) return false;
    int sqr=(int)sqrt(a*1.0);
    for (int i=2; i<=sqr; ++i) {
        if(a%i ==0) return false;
    }
    return true;
}
int l,k;
int i_(){
    scanf("%d %d",&l,&k);
    string s1;
    cin >> s1;
    for (int i=0; i+k-1<l; ++i) {
        string s2=s1.substr(i,k);
        int  num=stoi(s2);
        if(isPrime(num)){
            cout << s2<<"\n";
            return 0;
        }
    }
    printf("404\n");
    return 0;
}
