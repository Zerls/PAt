//
// 1086.cpp 
// pat 
// 
// Created by zerl on 2019/1/16. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
static vector<int> pre,in,post,value;
static void postOrder(int root,int start,int end){
    if(start >end) return;
    int i=start;// int i=root;
    while (i<end && pre[root]!=in[i]) i++; //while (pre[root]!=in[i]) i++;
    postOrder(root+1,start,i-1);
    postOrder(root+1+i-start,i+1,end); // postOrder(root+1-i+start,i+1,end);
    post.push_back(pre[root]);
}
int i1086(){
    int n,key=0,t;
    stack<int> s;
    char str[5];
    scanf("%d",&n);
    while (~scanf("%s",str)) {
        if(strlen(str)==4){
            scanf("%d",&t);
            pre.push_back(key);
            value.push_back(t);
            s.push(key);
            key++;
        }else{
            in.push_back(s.top());
            s.pop();
        }
    }
    postOrder(0,0,n-1);
    for (int i=0; i<n; ++i) {
        printf("%d%s",value[post[i]], (i!=n-1)?" ":"\n");
    }
    return 0;
}
