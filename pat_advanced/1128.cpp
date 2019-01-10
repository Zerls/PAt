//
// 1128.cpp 
// pat 
// 
// Created by zerl on 2019/1/10. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int i1128(){
    int k,n;
    cin >> k;
    for(int i=0;i<k;++i){
        cin >> n;
        bool result=true;
        vector<int> v(n);
        for(int j=0;j<n;++j){
            cin >> v[j];
            for(int t=0;t<j;++t){ // t<j
                if(v[j] == v[t]||abs(v[j]-v[t])==abs(t-j)){
                    result=false;
                    break;
                }
            }
        }
        printf("%s\n", result ==true ? "YES":"NO");
    }
    return 0;
}
