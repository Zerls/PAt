//
// 1154.cpp 
// pat 
// 
// Created by zerl on 2019/2/07. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n,m,k,a,b;
struct node{ int c1,c2;};
int main(){
    scanf("%d %d",&n,&m);
    vector<node> e(m);
    for (int i=0; i<m; ++i) 
        scanf("%d %d",&e[i].c1,&e[i].c2);
    scanf("%d",&k);
    while(k--){
        int flag=0;
        set<int> s;
        vector<int> v(n);
        for (int i=0; i<n; ++i) {
            scanf("%d",&v[i]);
            s.insert(v[i]);
        }
        for (int i=0; i<m; ++i) {
            if(v[e[i].c1]==v[e[i].c2]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            printf("No\n");
        }else
            printf("%d-coloring\n",(int)s.size());
    }
    return 0;
}
