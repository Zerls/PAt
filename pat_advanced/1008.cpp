//
//  1008.cpp
//  pat
//
//  Created by zerl on 2018/3/23.
//  Copyright © 2018年 zerl. All rights reserved.
//
#include "pat_advanced.h"
#include <iostream>
using namespace std;
int i1008() {
    freopen("1008.txt","r",stdin);
    int n, now = 0, sum = 0;
    cin >> n;
    while(cin >> n) {
        if(n > now)
            sum = sum + 6 * (n - now);
        else
            sum = sum + 4 * (now - n);
        now = n;
        sum += 5;
    }
    cout << sum;
    return 0;
}
