//
// 1074.cpp 
// pat 
// 
// Created by zerl on 2019/1/12. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

//#include <iostream>
//using namespace std;
//int i1074() {
//    int first, k, n, sum = 0;
//    cin >> first >> n >> k;
//    int temp, data[100005], next[100005], list[100005], result[100005];
//    for (int i = 0; i < n; i++) {
//        cin >> temp;
//        cin >> data[temp] >> next[temp];
//    }
//    while (first != -1) {
//        list[sum++] = first;
//        first = next[first];
//    }
//    for (int i = 0; i < sum; i++) result[i] = list[i];
//    for (int i = 0; i < (sum - sum % k); i++)
//        result[i] = list[i / k * k + k - 1 - i % k];
//    for (int i = 0; i < sum - 1; i++)
//        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
//    printf("%05d %d -1\n", result[sum - 1], data[result[sum - 1]]);
//    return 0;
//}

#include <iostream>
using namespace std;
static const int MAXN=100005;
struct Node{
    int addr,data,next;
}node_1074[MAXN];
int i1074(){
        int begin, k, n, sum = 0,ta, list[100005], result[100005];;
        cin >> begin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> ta;
            cin >> node_1074[ta].data >>  node_1074[ta].next;
        }
//        while (begin != -1) {
//            result[sum++]=list[sum] = begin;// result[sum]=list[sum] = begin;
//            node_1074[begin].next;
////            sum++;
//        }
    for(;begin != -1;begin = node_1074[begin].next)
            result[sum++]=list[sum] = begin;
//    for (int i = 0; i < sum; ++i) result[i] = list[i]; //
    for (int i=0; i<(sum-sum%k); ++i)
        result[i]=list[i/k*k+k-1-i%k];
        for (int i = 0; i < sum - 1; ++i)
            printf("%05d %d %05d\n", result[i], node_1074[result[i]].data, result[i + 1]);
        printf("%05d %d -1\n", result[sum - 1], node_1074[result[sum - 1]].data);
    return 0;
}
