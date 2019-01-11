//
// 1116.cpp 
// pat 
// 
// Created by zerl on 2019/1/11. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int ran[10010];
static bool isprime(int a) {
    if(a<=1) return false;
    int sqr=int(sqrt(a*1.0));
    for(int i=2;i<=sqr;++i)
        if(a%i ==0) return false;
    return true;
}
int i1116() {
    int n,k,temp;
    set<int> s;
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) {
        scanf("%d",&temp);
        ran[temp]=i;
    }
    scanf("%d",&k);
    while(k--) {
        scanf("%d",&temp);
        printf("%04d: ",temp);
        if(ran[temp]==0){
            printf("Are you kidding?\n");
        }else{
            if(s.find(temp)==s.end()){
                s.insert(temp);
                if(ran[temp]==1) {
                    printf("Mystery Award\n");
                }else if(isprime(ran[temp])) {
                    printf("Minion\n");
                }else
                    printf("Chocolate\n");
            }else
                printf("Checked\n");
        }
    }
    return 0;
}
