//
// 1137.cpp 
// pat 
// 
// Created by zerl on 2019/1/18. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct node_1137{
    string s;
    int gp,gm,gf,g;
};
static bool cmp1(node_1137 a,node_1137 b){
    return (a.g !=b.g) ?  a.g>b.g :a.s < b.s;
}
int i1137(){
    int p,m,n,a,id=1;
    vector<node_1137> v,ans;
    map<string, int> idx;
    string s;
    scanf("%d%d%d",&p,&m,&n);
    for (int i=0; i<p; ++i) {
        cin >> s >>a;
        if(a>=200){
            idx[s]=id++;
            v.push_back(node_1137{s,a,-1,-1,0});
        }
    }
    for (int i=0; i<m; ++i) {
        cin >> s >>a;
        if(idx[s] !=0) v[idx[s]-1].gm=a;
    }
    for (int i=0; i<n; ++i) {
        cin >> s >>a;
        if(idx[s] !=0){
            int temp=idx[s]-1;
            v[temp].g=v[temp].gf=a;
            if(v[temp].gm >v[temp].gf)
                v[temp].g=int(v[temp].gm*0.4+v[temp].gf*0.6+0.5);//v[temp].g=int(v[temp].gm*0.4+v[temp].gf*0.6); //约等于
            if(v[idx[s]-1].g>=60 && v[idx[s]-1].g <=100)
                ans.push_back(v[temp]);
        }
    }
    sort(ans.begin(),ans.end(),cmp1);
    for (int i=0; i<ans.size(); ++i)
        printf("%s %d %d %d %d\n",ans[i].s.c_str(),ans[i].gp ,ans[i].gm,ans[i].gf, ans[i].g);
    return 0;
}
