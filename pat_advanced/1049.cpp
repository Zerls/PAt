//
// 1049.cpp 
// pat 
// 
// Created by zerl on 2019/1/10. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
int i1049(){
    int n,left,now,right,ans=0,a=1;
    scanf("%d",&n);
    while(n/a){
        left=n/(a*10),now=n/a%10,right=n%a;
        if(now==0) ans+=left*a;
        else if(now ==1) ans+=left*a+1+right;
        else ans+=(left+1)*a;
        a*=10;
    }
    printf("%d",ans);
    return 0;
}
