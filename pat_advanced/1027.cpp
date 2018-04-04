//
// 1027.cpp 
// pat 
// 
// Created by zerl on 2018/4/4. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <iostream>

char Radix[]= {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int i1027 () {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("#");
    printf("%c%c",Radix[a/13],Radix[a%13]);
    printf("%c%c",Radix[b/13],Radix[b%13]);
    printf("%c%c",Radix[c/13],Radix[c%13]);
    return 0;
}
