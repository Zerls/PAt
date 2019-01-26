//
// 1099.cpp 
// pat 
// 
// Created by zerl on 2019/1/14. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static vector<int> in;
static int n,indexs=0,num=0; //num 输出空格控制
struct Node{
    int l,r,data;
}node_1099[110];
static void inlorder(int root) {
    if(root == -1) return ;
    inlorder(node_1099[root].l);
    node_1099[root].data =in[indexs++];
    inlorder(node_1099[root].r);
}
static void bfs(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int root =q.front();
        q.pop();
        num++;
        printf("%d%s",node_1099[root].data, num<n ?" ":"\n");
//        printf("%d%s",node_1099[root].data, ++num<n ?" ":"\n");
        if(node_1099[root].l != -1) q.push(node_1099[root].l);
        if(node_1099[root].r != -1) q.push(node_1099[root].r);
    }
}
int i1099() {
    scanf("%d", &n);
    in.resize(n);
    for(int i = 0 ; i < n; i++) scanf("%d %d", &node_1099[i].l,&node_1099[i].r);
    for(int i = 0 ; i < n; i++) scanf("%d", &in[i]);
    sort(in.begin(), in.end());
    inlorder(0);
    bfs(0);
    return 0;
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n, cnt, b[100];
//struct node {
//    int data, l, r, index, lebel;
//}a[110];
//bool cmp(node x, node y) {
//if (x.lebel != y.lebel) return x.lebel < y.lebel;
//return x.index < y.index;
//}
//void dfs(int root, int index, int lebel) {
//    if (a[root].l == -1 && a[root].r == -1) {
//        a[root] = {b[cnt++], a[root].l, a[root].r, index, lebel};
//    } else {
//        if (a[root].l != -1) dfs(a[root].l, index * 2 + 1, lebel + 1);
//        a[root] = {b[cnt++], a[root].l, a[root].r, index, lebel};
//        if (a[root].r != -1) dfs(a[root].r, index * 2 + 2, lebel + 1);
//    } }
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        cin >> a[i].l >> a[i].r;
//    for (int i = 0; i < n; i++)
//        cin >> b[i];
//    sort(b, b + n);
//    dfs(0, 0, 0);
//    sort(a, a + n, cmp);
//    for (int i = 0; i < n; i++) {
//        if (i != 0) cout << " ";
//        cout << a[i].data;
//    }
//    return 0;}
