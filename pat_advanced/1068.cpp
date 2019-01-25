//
// 1068.cpp 
// pat 
// 
// Created by zerl on 2019/1/24. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int dp[10010],w[10010];
static bool choice[10010][110];
static bool cmp1(int a, int b){return  a>b;}
int i1068(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&w[i]);
    sort(w+1, w+n+1, cmp1);
    for(int i = 1; i <= n; i++) {
        for (int j=m; j>=w[i]; j--) { // >=
            if(dp[j-w[i]]+w[i]>=dp[j]){// if(dp[j-w[i]]+w[i]>dp[j]){
                dp[j]=dp[j-w[i]]+w[i];
                choice[i][j]=true;
            }
        }
    }
    if(dp[m] !=m) printf("No Solution\n");
    else{
        vector<int> arr;
        int v=m,index=n;
        while(v>0){
            if(choice[index][v] ==true){
                arr.push_back(w[index]);
                v-=w[index];
            }
            index--;
        }
        for (int i=0; i<arr.size(); ++i) {
            printf("%d%s",arr[i],(i !=arr.size()-1)?" ":"\n");
        }
    }
    return 0;
}
