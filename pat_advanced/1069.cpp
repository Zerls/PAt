//
// 1069.cpp 
// pat 
// 
// Created by zerl on 2019/1/27. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp1(char &a,char &b){ return a>b;}
int main(){
    string s,a,b;
    cin >> s;
    s.insert(0,4-s.size(),'0');
    do{
        a=b=s;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp1);
        s=to_string(stoi(b)-stoi(a));
        s.insert(0,4-s.size(),'0');//new!!
        cout << b << " - " << a << " = "  << s<<"\n";
    }while(s!="6174" && s!="0000");//}while(s!="6174" ||s!="0000");
    
    return 0;
}
