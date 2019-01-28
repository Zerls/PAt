//
// 1120.cpp 
// pat 
// 
// Created by zerl on 2019/1/28. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <set>
using namespace std;
int getFriendNum(int num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;
num /= 10; 
}
return sum; }
int main() {
    set<int> s;
    int n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        s.insert(getFriendNum(num));
    }
    printf("%d\n", s.size());
    for(auto it = s.begin(); it != s.end(); it++) {
        if(it != s.begin()) printf(" ");
        printf("%d", *it);
    }
return 0; }



#include <iostream>
#include <map>
using namespace std;
int getID(string &s){
    int sum=0;
    for (int i=0; i<s.size(); ++i) 
        sum+=s[i]-'0';
    return sum;
}
map<int, int> m;
int main(){
    int n,cnt=0;
    string s;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        cin >>s;
        int id= getID(s);
        m[id]+=1;
        if(m[id]==1) cnt++;
    }
    cout <<cnt <<"\n";
    for (auto it=m.begin(); it != m.end(); ++it) {
        if(it != m.begin()) printf(" ");//
        if(it->second>=1) printf("%d",it->first);
    }
    return 0;
}