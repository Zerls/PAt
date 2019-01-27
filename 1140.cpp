//
// 1140.cpp 
// pat 
// 
// Created by zerl on 2019/1/27. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
int i(){
    string a,b;
    int n,j;
    cin >> a >> n;
    for (int cnt=0; cnt<n-1; ++cnt) {
        b="";
        for (int i=0; i<a.size(); i=j) {
            for(j=i;j<a.size() && a[j]==a[i];j++);
            b+=a[i]+to_string(j-i);//new! to_string();
        }
        a=b;
    }
    printf("%s\n",a.c_str());
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int i(){
//     string a,b;
//     int n;
//     cin >> a >> n;
//     for (int cnt=0; cnt<n-1; ++cnt) {
//         b="";
//         for (int j=0; j<a.size(); ) {
//             int num=0;
//             char c=a[j];
//             while(j<a.size()&&(c==a[j]) ){
//                 num++;
//                 j++;
//             }
//             b+=c+to_string(num);
            
//         }
//         a=b;
//     }
//     printf("%s\n",a.c_str());
//     return 0;
// }
