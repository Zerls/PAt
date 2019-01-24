//
// 1040.cpp 
// pat 
// 
// Created by zerl on 2019/1/24. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
static int dp[1005][1005];
int i1040(){
    string s;
    int cnt=1;//    int cnt=0; 单个字符与自身为回文
    getline(cin,s);
    for (int i=0; i<s.size(); ++i) {
        dp[i][i]=1;//边界
        if(i<s.size()-1 &&s[i] ==s[i+1]){
            dp[i][i+1]=1; //边界
            cnt=2;
        }
    }
    for (int l=3; l<=s.size(); ++l) {
        for (int i=0; i+l-1<=s.size(); ++i){
            int j=i+l-1;
//            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
//            if(dp[i][j]) cnt=l;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=dp[i+1][j-1];
                cnt=l;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
