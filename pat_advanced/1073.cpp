//
// 1073.cpp 
// pat 
// 
// Created by zerl on 2019/1/27. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string a,b;
    int i=1,exp=0,pos=0;
    cin >>a;
    for (; i<a.size(); ++i) {
        if(a[i]=='.') continue;
        if(a[i]=='E') break;
        b+=a[i];
    }
    pos=i;
    if(i+2 <a.size()){
        string s =a.substr(i+2);
        exp=stoi(s);
        if(a[i+1]=='+'){
            for (int j=0; j<exp-(pos-3); ++j) 
                b=b+"0";
        }else{
            s="0.";
            for (int j=1; j<exp; ++j) 
                s=s+"0";
            b=s+b;
        }
    }
    if(a[0]=='-')  b="-"+b;
    for (int i=0; i<b.size(); ++i) {
        if(a[pos+1]=='+'&& i==exp+2 ) printf(".");
        printf("%c",b[i]);
    }
    printf("\n");
    return 0;
}