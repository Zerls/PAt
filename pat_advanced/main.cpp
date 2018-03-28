//
//  main.cpp
//  pat
//
//  Created by zerl on 2018/3/23.
//  Copyright © 2018年 zerl. All rights reserved.
//
#include "pat_advanced.h"

int main() {
    
    int buket =10000,n;
    string str="hell";
    n= BKDRHash(str) % buket;
    printf("%d\n",n);
//    rational_sum();
    
    return 0;
}
