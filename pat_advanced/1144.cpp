//
// 1144.cpp 
// pat 
// 
// Created by zerl on 2019/1/28. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <map>
using namespace std;

int i(){
    int n,a,num=0;
    map<int,int> m;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        cin >> a;
        m[a]++;
    }
    while (++num) {
        if(m[num]==0) break;
    }

//  num=0
//  while(num){
//      if (m[num] == 0) break;
//      num++;
//  }
    cout << num;
    return 0;
}


