//
//  1015.cpp
//  pat
//
//  Created by zerl on 2018/3/23.
//  Copyright © 2018年 zerl. All rights reserved.
//

#include "pat_advanced.h"
#include <iostream>
#include <math.h>

void reverse(int &n ,int d) {
    int len = 0, arr[100];
    do{
        arr[len++] = n % d;
        n = n / d;
    }while(n != 0);
    for(int i = 0; i < len; i++)
        n = n * d + arr[i];
}
bool isPrime (int n) {
    if (n <= 1) return false;
    int sqr = int(sqrt(n*1.0));
    for (int i =2; i <= sqr; ++i)
        if (n % i == 0) return false;
    return true;
}

int i1015() { 
    freopen("1015.txt","r",stdin);
    int n,d;
    while (1) {
        scanf("%d",&n);
        if (n < 0) break;
        scanf("%d",&d);
        if (!isPrime(n)) {
            printf("No\n");
            continue;
        }
        reverse(n,d);
        printf("%s", isPrime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}
