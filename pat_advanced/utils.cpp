//
//  utils.cpp
//  pat
//
//  Created by zerl on 2018/3/25.
//  Copyright © 2018年 zerl. All rights reserved.
//

#include "pat_advanced.h"

// BKDR Hash Function
unsigned int BKDRHash(string & str) {
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    
    for (int i = 0; i<str.length(); i++)
        hash = hash * seed + (str[i]);
    
    return (hash & 0x7FFFFFFF);
}

long long gcd(long long a,long long b)  { return b==0 ? abs(a): gcd(b,a%b); }
int gcd(int a,int b){ return  b==0 ? abs(a): gcd(b,a%b); }


void test(bool test,string str){
    if(test){
        freopen(str.c_str(),"r",stdin);
        printf("==test==\n");
    }
}
