//
// 1092.cpp 
// pat 
// 
// Created by zerl on 2019/1/28. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 


#include <iostream>
using namespace std;
int book[256];
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        book[a[i]]++;
    int result = 0;
    for (int i = 0; i < b.length(); i++) {
        if (book[b[i]] > 0)
            book[b[i]]--;
        else
result++; }
    if(result != 0)
        printf("No %d", result);
else
        printf("Yes %d", a.length() - b.length());
    return 0;
}


#include <iostream>
#include <map>
using namespace std;
map<char,int> m1,m2;
int main(){
    int num2=0,flag=1;
    string s1,s2;
    cin >> s1 >> s2;
    for (int i=0; i<s1.size(); ++i)
        m1[s1[i]]++;
    for (int i=0; i<s2.size(); ++i)
        m2[s2[i]]++;
    for (auto it=m2.begin(); it !=m2.end(); ++it){
        if(it->second > m1[it->first]){
            num2+=(it->second-m1[it->first]);
            flag=0;
        }
    }
    if(flag){
        printf("Yes %d\n",s1.size()-s2.size());
    }else{
        printf("No %d\n",num2);
    }
    return 0;
}

