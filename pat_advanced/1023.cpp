//
// 1023.cpp 
// pat 
// 
// Created by zerl on 2018/10/24. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <string>
using namespace std;
int i1023(){
    char num[22];
    scanf("%s",num);
    
    int n=int(strlen(num)),flag=0,scan[10]={0};
    for (int i =n-1; i>=0; i--) {
        int temp=num[i]-'0'; //assert: temp->[1,9]
        scan[temp]+=1;
        temp=2*(temp)+flag;
        flag=0;
        if(temp >= 10){ //?->  >  >=
            temp-=10;
            flag=1;
        }
        num[i]=temp+'0';
        scan[temp]-=1;
    }
    
    bool flag1=false;
    for (int i=0; i<10; i++)
        if(scan[i] !=0) flag1=true;
    
    printf("%s", flag||flag1 ? "No\n":"Yes\n");
    if(flag==1) printf("1");  //P?:大整数计算未考虑末位进位
    printf("%s",num);
    return 0;

}
//题目理解问题
//c语言字符串的用法  char[]  strlen()
//边界判断
