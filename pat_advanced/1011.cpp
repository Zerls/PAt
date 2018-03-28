//
//  1011.cpp
//  pat
//
//  Created by zerl on 2018/3/23.
//  Copyright © 2018年 zerl. All rights reserved.
//

#include "pat_advanced.h"
#include <iostream>
using namespace std;

const string STR= "WTL";

int i1011() {
    freopen("1011.txt","r",stdin);
    float max=0.0,sum=1.0;
    for (int i =0; i < 3; ++i) {
        float a,b,c;
        cin >> a >> b >>c ;
        a > b ? max = a : max = b;
        c > max ? max=c : 0;
        if (max==a) cout << STR[0];
        else if (max==b) cout << STR[1];
        else cout << STR[2];
        cout << " ";
        sum *= max;
    }
    printf("%.2f",(sum*0.65-1)*2);
    return 0;
}
