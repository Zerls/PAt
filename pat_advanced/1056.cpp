//
// 1056.cpp 
// pat 
// 
// Created by zerl on 2019/1/15. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
//
#include <cstdio>
#include <queue>
using namespace std;
struct mouse {
    int weight,R;
}mouse_1056[1010];
int i1056() {
    int np, ng, order;
    queue<int> q;
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++)  scanf("%d", &mouse_1056[i].weight);
    for(int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np, group;//temp 为当前轮的比赛总老鼠数，group 为组数
    while(q.size() != 1) {
        group =(temp %ng ==0)? (temp/ng):(temp/ng+1);
        for(int i = 0; i < group; i++) {
               int k=q.front();
            for (int j=0; j<ng; ++j) {
                if(i*ng+j >=temp) break; //if(i*group+j >=temp) break;
                int t =q.front();
                if(mouse_1056[t].weight>mouse_1056[k].weight) k=t;
                mouse_1056[t].R=group+1;
                q.pop();
            }
            q.push(k);
        }
        temp=group;
    }
    mouse_1056[q.front()].R=1;
    for(int i = 0; i < np; i++)
        printf("%d%s", mouse_1056[i].R,(i < np - 1) ? " ":"\n");
    return 0;
}



//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct node {
//    int weight, index, rank, index0;
//};
//static bool cmp1(node a, node b) {
//    return a.index0 < b.index0;
//}
//int i1056() {
//    int n, g, num;
//    scanf("%d%d", &n, &g);
//    vector<int> v(n);
//    vector<node> w(n);
//    for(int i = 0; i < n; i++)
//        scanf("%d", &v[i]);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &num);
//        w[i].weight = v[num]; //
//        w[i].index = i;
//        w[i].index0 = num;
//    }
//    queue<node> q;
//    for(int i = 0; i < n; i++)
//        q.push(w[i]);
//    while(!q.empty()) {
//        int size = q.size();
//        if(size == 1) {
//            node temp = q.front();
//            w[temp.index].rank = 1;
//            break;
//        }
//        int group = size / g;
//        if(size % g != 0)
//            group += 1;
//        node maxnode;
//        int maxn = -1, cnt = 0;
//        for(int i = 0; i < size; i++) {
//            node temp = q.front();
//            w[temp.index].rank = group + 1;
//            q.pop();
//            cnt++;
//            if(temp.weight > maxn) {
//                maxn = temp.weight;
//                maxnode = temp;
//            }
//            if(cnt == g || i == size - 1) {
//                cnt = 0;
//                maxn = -1;
//                q.push(maxnode);
//            }
//        }
//    }
//    sort(w.begin(), w.end(), cmp1);
//    for(int i = 0; i < n; i++) {
//        if(i != 0) printf(" ");
//        printf("%d", w[i].rank);
//    }
//
//    return 0;
//
//}
