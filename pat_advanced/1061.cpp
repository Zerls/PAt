//
// 1061.cpp 
// pat 
// 
// Created by zerl on 2019/1/27. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <cctype>
using namespace std;
string DAY[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    string s1,s2,s3,s4;
    int day=-1,hh=0,mm=0,i=0,j=0;
    cin >> s1 >> s2 >> s3 >> s4;

    while (i<s1.size() &&i <s2.size()) {
        if(s1[i]==s2[i] && (s1[i] >= 'A' && s1[i] <= 'G')){
            day=s1[i]-'A';
            break;
        }
        i++;
    }
    i=i+1;
    while (i<s1.size() &&i <s2.size()) {
        if(s1[i]==s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || isdigit(s1[i]))){
           isupper(s1[i]) ? hh=s1[i]-'A'+10:hh=s1[i]-'0';
            break;
        }
        i++;
    }
    while (j<s3.size() &&j <s4.size()) {
        if(s3[j]==s4[j] && isalpha(s3[j])){
             mm=j;
            break;
        }
        j++;
    }
    printf("%s %02d:%02d\n",DAY[day].c_str(),hh,mm);
    return 0;
}