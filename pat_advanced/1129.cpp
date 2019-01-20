//
// 1129.cpp 
// pat 
// 
// Created by zerl on 2019/1/20. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <set>
using namespace std;
static int book[50001];
struct Node_1129 {
    int value,cnt;
    bool operator < (const Node_1129 &a) const{
        return (cnt !=a.cnt) ? cnt >a.cnt : value <a.value;
    }
};

int i1129(){
    int n,k,num;
    set<Node_1129> s;
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; ++i) {
        scanf("%d",&num);
        if(i !=0){
            int tempk=0;
            printf("%d:",num);
            for (auto it=s.begin(); tempk<k &&it !=s.end(); ++it) {
                printf(" %d",it->value);
                tempk++;
            }
            printf("\n");
        }
       auto it= s.find(Node_1129{num,book[num]});
        if(it !=s.end()) s.erase(it);
        book[num]++;
        s.insert(Node_1129{num,book[num]});
    }
    return 0;
}
