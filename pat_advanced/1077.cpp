//
// 1077.cpp 
// pat 
// 
// Created by zerl on 2019/1/10. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
using namespace std;
int i1077() {
    int n;
    scanf("%d\n", &n);
    string ans;
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        reverse(s.begin(), s.end());
        if(i == 0) {
            ans = s;
           // continue;
        } else {
            int minlen = (s.length() <ans.length()) ? s.length():ans.length();
            for(int j = 0; j < minlen; j++) {
                if(ans[j] != s[j]) {
                    ans = ans.substr(0, j);
                    break;
                } }
        } }
    reverse(ans.begin(), ans.end());
    if (ans=="") ans = "nai";
    cout << ans << "\n";
    return 0;
}


// ?? NR
//#include <iostream>
//#include <algorithm>
//using namespace std;
//static string getKuchiguse(string s1,string s2){
//   int len=(s1.size() < s2.size())?s1.size():s2.size();
//    string s;
//    for (int i=0; i<len; ++i)
//        if(s1[i]==s2[i]) s +=s1[i];
//    return s;
//}
//int i1077(){
//    int n;
//    scanf("%d\n",&n);
//    string ans;
//    for (int i=0; i<n; ++i) {
//        string s;
//        getline(cin, s);
//        reverse(s.begin(), s.end());
//        if(i==0) ans=s;
//        else ans=getKuchiguse(ans,s);
//    }
//    reverse(ans.begin(), ans.end());
//    if(ans=="") cout << "nai\n";
//    else cout << ans << "\n";
//
//    return 0;
//}
