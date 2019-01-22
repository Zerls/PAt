//
// 1051.cpp 
// pat 
// 
// Created by zerl on 2019/1/22. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int i1051(){
    int m,n,k;
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<k;i++){
        stack<int> s;
        vector<int> v(n+1);//vector<int> v(n);
        for(int j=1;j<=n;j++){
            scanf("%d",&v[j]);
        }
        int current=1;
        for(int j=1;j<=n;j++){
            s.push(j);
            if(s.size()>m) break;
            while(!s.empty()&&s.top() ==v[current]){
                s.pop();
                current++;
            }
        }
        printf("%s\n",(current==n+1)?"YES":"NO");
    }
    return 0;
}
