//
// 1145.cpp 
// pat 
// 
// Created by zerl on 2018/12/18. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
//

#include <iostream>
#include <vector>
using namespace std;

static bool isPrime(int n){
    if(n<=1) return false;
    for (int i=2; i*i<=n; ++i) {
//      P:  for (int i=2; i*i<n; ++i) {
        if(n%i==0) return false;
    }
    return true;
}

int i1145(){
    int msize,n,m,a;
    scanf("%d %d %d",&msize,&n,&m);
    while (!isPrime(msize)) msize++;
    vector<int> v(msize);
    for (int i=0; i<n; ++i) {
        int flag=0;
        scanf("%d",&a);
        for (int j=0; j<msize; ++j) {
            int pos = (a+j*j)%msize;
            if(v[pos]==0){
                v[pos]=a;
                flag=1;
                break;
                
            }
        }
        if(flag==0)printf("%d cannot be inserted.\n",a);
    }
    int ans=0;
    for (int i=0; i<m; ++i) {
        scanf("%d",&a);
        
        for (int j=0; j<=msize; ++j) {
//        P:    for (int j=0; j<msize; ++j) { ??
            int pos =(a+j*j)%msize;
            ans++;
//            if(a==11) printf("ans: %d\n",ans);
          //  if(a==15) printf("%d",j);
            if(v[pos]==a||v[pos]==0) break;
        }
    }
    
    printf("%.1f\n",ans*1.0/m);
    return 0;
}
