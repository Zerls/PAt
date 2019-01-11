//
// 1057.cpp 
// pat 
// 
// Created by zerl on 2019/1/11. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <stack>
using namespace std;
#define lowbit(i) ((i) & (-i))
static const int maxn = 100010;
static int c[maxn];
static stack<int> s;
static void update(int x, int v) {
    for(int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
static int getsum(int x) {
    int sum=0;
    for(int i = x; i >0 ; i -= lowbit(i))
        sum+=c[i];
    return sum;
}
static void PeekMedian() {
    int l=1,r=maxn,mid,k=(s.size()+1)/2;
    while (l<r) {
        mid=(l+r)/2;
        if(getsum(mid)>=k) //getsum(mid)>k
            r=mid;
        else
            l=mid+1;
    }
    cout <<l <<"\n"; //cout << mid <<"\n";
}

int i1057(){
    int n,k;
    string str;
    scanf("%d",&n);
    while (n--) {
        cin >> str;
        if(str[1]=='u'){
            cin >> k;
            s.push(k);
            update(k, 1);
        }else if(str[1]=='o'){
            if(!s.empty()){
                update(s.top(),-1);
                cout << s.top() << "\n";
                s.pop();
            }else
                cout << "Invalid\n";
        }else{
            if(!s.empty())
                PeekMedian();
            else
                cout << "Invalid\n";
        }
    }
    return 0;
}
