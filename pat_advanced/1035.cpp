//
// 1035.cpp 
// pat 
// 
// Created by zerl on 2018/4/4. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include "pat_advanced.h"
#include <iostream>
#include <vector>
using namespace std;

int i1035() {
    freopen("1035.txt", "r",stdin);
    int n;
    cin >> n;
    vector<string> str;
    for (int i =0; i < n; ++i) {
        string name,s;
        bool flag=0;
        cin >> name >> s;
        for (int j =0; j<s.length(); ++j) {
            switch (s[j]) {
                case '1': s[j]='@';flag=1;break;
                case '0': s[j]='%';flag=1;break;
                case 'l': s[j]='L';flag=1;break;
                case 'O': s[j]='o';flag=1;break;
            }
        }
        if (flag) {
            string temp = name + " " + s;
            str.push_back(temp);
        }
    }
    
    if (str.size() != 0) {
        cout << str.size() << endl;
        for (auto iter = str.begin(); iter < str.end(); ++iter)
            cout << *iter << endl;
    }else if (n == 1)
        cout << "There is 1 account and no account is modified" ;
    else
        cout << "There are "<< n <<" accounts and no account is modified" ;
    
    return 0;
}
