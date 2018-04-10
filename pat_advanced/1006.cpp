//
// 1006.cpp 
// pat 
// 
// Created by zerl on 2018/4/10. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <climits>
using namespace std;

int i1006() {
    //freopen("1006.txt", "r", stdin);
    string str ,locker,unlocker;
    int n, h1,m1,s1,h2,m2,s2, max=INT_MIN,min=INT_MAX;
    
    cin >> n ;
    while(n--){
        cin >> str ;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int temp1 = h1*3600+m1*60+s1;
        int temp2 = h2*3600+m2*60+s2;
        if (temp1 < min){
            min = temp1;
            unlocker = str;
        }
        if (temp2 > max){
            max = temp2;
            locker = str;
        }
    }
    cout << unlocker <<" "<< locker;
    
    return 0;
}
