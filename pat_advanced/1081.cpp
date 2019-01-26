//

//  pat
//
//  Created by zerl on 2018/3/27.
//  Copyright © 2018年 zerl. All rights reserved.
//

#include "pat_advanced.h"
#include <iostream>

//long long gcd(long long a,long long b)  { return b==0 ? abs(a): gcd(b,a%b); }

struct fraction{
    long long up,down;
    
    fraction():up(0),down(1){}
    fraction(long long _up,long long _down):up(_up),down(_down){}
    
    void reduction(){
        if(down < 0) {
            up   = -up;
            down = -down;
        }
        if(up == 0) down =1;
        else {
            long long d =gcd(up, down);
            up /=d;
            down /=d;
        }
    }
    
    void to_string() {
        if(down == 1 ) printf("%lld",up);
        else if(abs(up) > down) printf("%lld %lld/%lld",up/down,abs(up%down),down);
        else printf("%lld/%lld",up,down);
    }
};

void frac_add(fraction &a,const fraction &b) {
    a.up = a.up * b.down + b.up * a.down;
    a.down *=b.down;
}


int rational_sum() {
    freopen("Rational_Sum_input.txt", "r", stdin);
    int num;
    scanf("%d",&num);
    fraction frac[num],sum=fraction();
    for (int i = 0; i < num; ++i) {
        scanf("%lld/%lld",&frac[i].up,&frac[i].down);
        frac_add(sum, frac[i]);
        sum.reduction();
    }
    
    sum.to_string();
    return 0;
}

int rational_sum_liu() {
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b);
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
        gcdvalue = gcd(suma, sumb);
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if(integer != 0) {
        printf("%lld", integer);
        if(suma != 0) printf(" ");
    }
    if(suma != 0)
        printf("%lld/%lld", suma, sumb);
    if(integer == 0 && suma == 0)
        printf("0");
    return 0;
}
