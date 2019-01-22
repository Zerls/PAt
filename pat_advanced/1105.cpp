//
// 1105.cpp 
// pat 
// 
// Created by zerl on 2019/1/22. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
static int fn(int N){
    int n=(int)sqrt(N*1.0);
    while (n>=1) {
        if(N%n ==0) return n;
        n--;
    }
    return 1;
}
static bool cmp(int a,int b){
    return a>b;
}
int i1105(){
    int N,t=0;
    scanf("%d",&N);
    vector<int> v(N);
    for (int i=0; i<N; ++i) {
        scanf("%d",&v[i]);
    }
    sort(v.begin(), v.end(), cmp);
    int n=fn(N);
    int m=N/n;
    vector< vector<int>> b(m,vector<int>(n));
    int level = m / 2 + m % 2;
    
    for (int i = 0; i < level; i++) {
        int U=i+1,D=m-2-i,L=i,R=n-1-i;
        for (int j = L; j <= R && t <= N - 1; j++)
            b[L][j] = v[t++];
        for (int j = U; j <= D && t <= N - 1; j++)
            b[j][R] = v[t++];
        for (int j = R; j >= L && t <= N - 1; j--)
            b[D+1][j] = v[t++];
        for (int j = D; j >= U && t <= N - 1; j--)
            b[j][L] = v[t++];
    }
//    int level = m / 2 + m % 2;
//    for (int i = 0; i < level; i++) {
//        for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
//            b[i][j] = v[t++];
//        for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
//            b[j][n - 1 - i] = v[t++];
//        for (int j = n - i - 1; j >= i && t <= N - 1; j--)
//            b[m - 1 - i][j] = v[t++];
//        for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
//            b[j][i] = v[t++];
//    }
/**
|-----------|
| * * * * R |
| ----------|
| U|* * *|* |
| *|* * *|* |
| *|* * *|* |
| *|* * *|D |
|-----------|
| L * * * * |
|-----------|
 
 **/
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j){
            printf("%d%s",b[i][j],(j!=n-1)?" ":"\n");
        }
    }
    return 0;
}
