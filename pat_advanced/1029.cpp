//
// 1029.cpp 
// pat 
// 
// Created by zerl on 2019/1/20. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

//#include <iostream>
//#include <vector>
//using namespace std;
//static int maxn=0x7fffffff;
//static int v1[1000010],v2[1000010];
//int i1029(){
//    int n1,n2;
//    scanf("%d",&n1);
//    for(int i=0;i<n1;++i) {
//        scanf("%d",&v1[i]);
//    }
//    scanf("%d",&n2);
//    for(int i=0;i<n2;++i) {
//        scanf("%d",&v2[i]);
//    };
//    v1[n1]=maxn;
//    v2[n2]=maxn;
//    int medianPos=(n1+n2-1)/2,count=0,i1=0,i2=0;
//    while (count<medianPos) {
//        if(v1[i1] <v2[i2]) i1++;
//        else i2++;
//        count++;
//    }
//    v1[i1] <v2[i2] ? printf("%d\n",v1[i1]): printf("%d\n",v2[i2]);
//    return 0;
//}
// 最后测试点 内存超限


#include <iostream>
using namespace std;
int k[200005];
int i1029(){
    int n,m,count=0,temp,i=1;
    cin >> n;
    for (int i=1; i<=n; ++i)
        scanf("%d",&k[i]);
    k[n+1]=0x7fffffff;//int 最大值
    cin >> m;
    int mid=(n+m+1)/2;
    for (int j=1; j<=m; ++j) {
        scanf("%d",&temp);
        while(k[i]<temp){
            count++;
            if(count ==mid) cout <<k[i];
            i++;
        }
        count++;
        if(count ==mid) cout << temp; //if(count ==mid) cout <<k[i];
    }
    while (i <=n){
        if(count ==mid) cout <<k[i];
        count++;
        i++;
    }
    return 0;
}
