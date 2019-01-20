//
// 1089.cpp 
// pat 
// 
// Created by zerl on 2019/1/20. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int i1089(){
    int n,a[105],b[105],i,j;
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
        scanf("%d",&a[i]);
    for (int i=0; i<n; ++i)
        scanf("%d",&b[i]);
//    while(i<n-1 &&b[i]<=b[i+1]) i++; //while(i<n-1 &&b[i]<b[i+1]) i++;
//    j=i+1;
//    while (j<n && a[j]==b[j]) j++;
        for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
        for (j = i + 1; a[j] == b[j] && j < n; j++);
    printf("%s",(j==n)? "Insertion Sort\n":"Merge Sort\n");
    if(j==n){
        sort(a,a+i+2);
    }else{
        int k = 1, flag = 1;
        while(flag) {
            flag=0;
            for (i=0; i<n; ++i)
                if(a[i]!=b[i])
                    flag=1;
            k = k * 2;
            for (i = 0; i < n / k; i++)
                sort(a+i*k, a+(i+1)*k);
            sort(a+n/k*k, a+n);//sort(a+n/k*n, a+n);
        }
    }
    for (j=0; j<n; ++j)
        printf("%d%s",a[j], (j!=n-1)?" ":"\n" );
    return 0;
}


