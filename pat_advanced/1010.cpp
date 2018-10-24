//
// 1010.cpp 
// pat 
// 
// Created by zerl on 2018/10/20. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

long long convert(string str,long long radix){
    long long  num=0;
    int temp,index=0;
    for (auto it=str.rbegin(); it<str.rend(); ++it) {
        temp=(isdigit(*it))? *it-'0':*it-'a'+10; //Note--
        num+=temp*pow(radix,(index++));
    }
    return num;
}

long long find_radix(string str,long long num){
    char it =*max_element(str.begin(), str.end()); //Note--
    long long low=( isdigit(it) ? it-'0':it-'a'+10)+1; //P:?-
    long long high=max(num,low);
    while (low<=high) {  // <  ->  <=
        long long mid=(low+high)/2; // 二分法
        long long numf= convert(str,mid);
        if(numf<0||numf>num){
            high=mid-1;
        }else if(numf==num){
            return mid;
        }else{
            low=mid+1;
        }
    }
    return -1;
}

int i1010(){
//    printf("%lld",convert("110", 2));
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    (result_radix != -1 ) ? printf("%lld", result_radix) : printf("Impossible") ;
    return 0;
}
