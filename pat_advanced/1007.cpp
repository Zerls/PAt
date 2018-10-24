//
// 1007.cpp 
// pat 
// 
// Created by zerl on 2018/10/19. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
const int K=10010;
int A[K],dp[K],s[K];
int i1007_1(){
    bool flag=false;
    int k,maxn=INT_MIN,last=0;
    scanf("%d",&k);
    for (int i=0; i<k; ++i) {
        scanf("%d",&A[i]);
        if(A[i]>0) flag=true;
        if(i==0){
            dp[0]=A[0];
        }else{
            dp[i]=max(A[i]+dp[i-1],A[i]);
        }
        if(maxn < dp[i]){
            maxn = dp[i];
            last=i;
        }
    }
    if(flag == false) {
        cout <<0<<" "<<A[0]<<" "<<A[k-1]<<endl;
        return 0;
    }
    int num=dp[last],first =last;
    while(num)
        num-=A[first--];
    cout <<dp[last]<<" "<<A[first+1]<<" "<<A[last]<<endl;
    return 0;
}
/*
_1
 动态规划
    状态转移方程
 空间O(n)
 时间O(n)
 问题
    忽略情况 num=0 A[last]=0
 与_2对比
_2  数列方法
 */

int i1007_2() {
    int n;
    scanf("%d", &n);
    vector<int> vss(n);
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &vss[i]);
        temp = temp + vss[i];
        if (temp < 0) {
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) sum = 0;
    printf("%d %d %d", sum, vss[leftindex], vss[rightindex]);
    return 0;
}
// 3 -1 0 -2
