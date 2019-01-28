//
// 1084.cpp 
// pat 
// 
// Created by zerl on 2019/1/28. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) ==string::npos)
            ans += toupper(s1[i]);
    cout << ans;
return 0; 
}


#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    map<char,int> m1;
    for (int i=0; i<s2.size(); ++i) {
        char c=toupper(s2[i]);
        m1[c]+=1;
    }
    for (int i=0; i<s1.size(); ++i) {
        char c=toupper(s1[i]);
        if(m1[c]==0 ){ 
            printf("%c",c);
            m1[c]--;}
    }
    return 0;
}
