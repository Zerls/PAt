//
// 1139.cpp 
// pat 
// 
// Created by zerl on 2019/1/15. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
static unordered_map<int, bool> f; //friends
struct Node{
    int a,b;
};
static bool cmp1 (Node a,Node b){
    return a.a !=b.a ? a.a<b.a: a.b<b.b ;
}
int i1139(){
    int n,m,k;
    string s1,s2;
    vector<int> v[10000];
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; ++i) {//for (int i=0; i<n; ++i) {
        cin >> s1 >>s2;
        int v1=abs(stoi(s1)),v2=abs(stoi(s2));
        if(s1.size()==s2.size()){
            v[v1].push_back(v2);
            v[v2].push_back(v1);
        }
        f[v1*10000+v2]=f[v2*10000+v1]=true;
    }
    scanf("%d",&k);
    for (int i=0; i<k; ++i) {
        int v1,v2;
        vector<Node> ans;
        cin >> v1 >> v2;
        v1=abs(v1),v2=abs(v2);
        for (int j=0; j<v[v1].size(); ++j) {
            for (int k=0; k<v[v2].size(); ++k) {
                if(v[v1][j]==v2||v[v2][k]==v1) continue;
                if( f[v[v1][j]*10000+v[v2][k]]==true){
                    ans.push_back(Node{v[v1][j],v[v2][k]});
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp1);
        printf("%d\n",(int)ans.size());
        for (int j=0; j<ans.size(); ++j) {
            printf("%04d %04d\n",ans[j].a,ans[j].b);
        }
    }
    return 0;
}
