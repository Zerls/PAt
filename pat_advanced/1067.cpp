//
// 1067.cpp 
// pat 
// 
// Created by zerl on 2019/1/2. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;

int i1067(){
    int n,t,cnt=0,a[100010],b[100010];//t : temp var
    cin >>n;
    for (int i=0; i<n; ++i) {
        cin >> t;
        a[t]=i;
        b[a[t]] = t ;
    }
    for (int i=0; i<n; ++i) {

        
        if(i!=a[i]){
            while (0!=a[0]) {
                swap(a[0], a[a[0]]);
                cnt++;
                
//                for(int j=0;j<n;++j){   //swap交换过程显示
//                    b[a[j]] = j;}
//                for (int j=0; j<n; ++j){
//                    printf("%d ",b[j]);}
//                printf("\n");
            }
            if(i!=a[i]){
                swap(a[0], a[i]);
                cnt++;
                
//                for(int j=0;j<n;++j){  //swap交换过程显示
//                    b[a[j]] = j;}
//                for (int j=0; j<n; ++j){
//                    printf("%d ",b[j]);}
//                printf("\n");
            }
        }
        
    }
    printf("%d\n",cnt);
    return 0;
}
