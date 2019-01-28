//
// 1124.cpp 
// pat 
// 
// Created by zerl on 2019/1/28. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int m,n,s;
    string temp;
    vector<string> v;
    map<string,int> ma;
    scanf("%d %d %d",&m,&n,&s);
    v.push_back("");
    for (int i=1; i<=m; ++i) {
        cin >> temp;
        v.push_back(temp);
    }
    for (int i=s; i<v.size(); ) {
        if(ma[v[i]]==0){
            printf("%s\n",v[i].c_str());
            ma[v[i]]++;
            i+=n;
        }else
            i+=1;
    }
    if(s>v.size()-1) printf("Keep going...\n");
    return 0;
}


#include <iostream>
#include <map>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    string str;
    map<string, int> mapp;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        cin >> str;
        if (mapp[str] == 1) s = s + 1;
        if (i == s && mapp[str] == 0) {
            mapp[str] = 1;
            cout << str << endl;
            flag = true;
            s = s + n;
} }
    if (flag == false) cout << "Keep going...";
return 0;
}