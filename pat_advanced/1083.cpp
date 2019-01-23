//
// 1083.cpp 
// pat 
// 
// Created by zerl on 2019/1/23. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
    string name,id;
};
static vector<student> v(101);
int i1083(){
    int n,tscore,sl,sh,flag=0;;
    string tname,tid;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        cin >> tname >> tid >> tscore;
        v[tscore].name=tname;
        v[tscore].id=tid;
    }
    scanf("%d %d",&sl,&sh);
    for (int i=sh; i>=sl; --i) {
        if(v[i].name !=""){
            printf("%s %s\n",v[i].name.c_str(),v[i].id.c_str());
            flag=1;
        }
    }
    if(flag==0) printf("NONE\n");
    return 0;
}
