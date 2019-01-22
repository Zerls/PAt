//
// 1093.cpp 
// pat 
// 
// Created by zerl on 2019/1/22. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
static  int cnt_p,cnt_t,ans;
int i1093(){
    string s;
    cin >> s;
    for (int i=0; i<s.size(); ++i)
        if(s[i]=='T') cnt_t++;
    
    for (int i=0; i<s.size(); ++i) {
        if(s[i]=='P'){ cnt_p++;}
        else if(s[i]=='A'){
            // ans+=cnt_p*cnt_t%1000000007;
            ans = (ans + (cnt_p * cnt_t) % 1000000007) %1000000007;
        }
        else  if(s[i]=='T'){
            cnt_t--;}
    }
    printf("%d\n",ans);
    return 0;
}
//注意数据范围 int( -2^31 ~ 2^31-1 -> -2*10^9 ~ 2*10^9)
//该题统计过程中数据溢出 tips： Since the result may be a huge number, you only have to output the result moded by 1000000007.
