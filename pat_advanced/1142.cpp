//
// 1142.cpp 
// pat 
// 
// Created by zerl on 2019/1/18. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
static int e[205][205];
int i1142(){
    int nv=0,ne,m,k,a,b;
    scanf("%d%d",&nv,&ne);
    for (int i=0; i<ne; ++i) {
        scanf("%d%d",&a,&b);
        e[a][b]=e[b][a]=1;
    }
    scanf("%d",&m);
    for (int i=0; i<m; ++i) {
        scanf("%d",&k);
        int v[k+1],have[205]={0},isMax=1,isClique=1;
        for (int j=1; j<=k; ++j) {
            scanf("%d",&v[j]);
            have[v[j]]=1;
        }
        for (int i=1; i<=k; ++i) {
            if (isClique==0 ) break;
            for (int j=i+1; j<=k; ++j) {
                if (e[v[i]][v[j]]==0) {
                    isClique=0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if(isClique==0) continue;
        for (int i=1; i<=nv; ++i) {
            if( have[i]==0){
                for (int j=1; j<=k; ++j) {
                    if(e[v[j]][i] ==0) break; //
                    if(j== k) isMax=0; //看是否存在一个点满 和集合中所有的结点相连
                }
            }
            if(isMax== 0){
                printf("Not Maximal\n");
                break;
            }
        }
        if(isMax==1) printf("Yes\n");
    }
    return 0;
}
//#include <iostream>
//#include <vector>
//using namespace std;
//static int e[205][205];
//static vector<int> v;
//int i1142(){
//    int nv=0,ne,m,k,a,b;
//    scanf("%d%d",&nv,&ne);
//    for (int i=0; i<ne; ++i) {
//        scanf("%d%d",&a,&b);
//        e[a][b]=e[b][a]=1;
//    }
//    scanf("%d",&m);
//    for (int i=0; i<m; ++i) {
//        scanf("%d",&k);
//        int v[k+1],have[205]={0},isMax=1,isClique=1;
//        for (int j=1; j<=k; ++j) {
//            scanf("%d",&v[j]);
//            have[v[j]]=1;
//        }
//        for (int i=1; i<=k; ++i) {
//            if (isClique==0 ) break;
//            for (int j=i+1; j<=k; ++j) {
//                if (e[v[i]][v[j]]==0) {
//                    isClique=0;
//                    printf("Not a Clique\n");
//                    break;
//                }
//            }
//        }
//        if(isClique==0) continue;
//        for (int i=1; i<=nv; ++i) {
//            if( have[i]==0){
//                for (int j=1; j<=k; ++j) {
////                 //   if(e[i][v[j]] ==1){
////                        printf("Not Maximal\n");
////                        isMax=0;
////                        break;
////                    }
//                    if(e[v[j]][i] ==0) break;
//                    if(j== k) isMax=0;
//                }
//            }
//            if(isMax== 0){
//                printf("Not Maximal\n");
//                break;
//            }
//        }
//        if(isMax==1) printf("Yes\n");
//
//    }
//    return 0;
//}
