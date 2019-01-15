//
// 1048.cpp 
// pat 
// 
// Created by zerl on 2019/1/15. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <map>
using namespace std;
static map<int,int> ma;
int i1048(){
    int n,m,temp;
    scanf("%d %d",&n,&m);
    for (int i=0; i< n; ++i) {
        scanf("%d",&temp);
        ma[temp]++;
        
    }
    for (int i=0; i<m; ++i) {
        if(ma[i]){
        ma[i]--;
        if(ma[m-i]){
             printf("%d %d\n",i,(m-i));
            return 0;
        }
        ma[i]++;
        }
    }
    printf("No Solution\n");
    return 0;
}

//#include <iostream>
//#include <map>
//#include <vector>
//using namespace std;
//static int ma[1001];
//int main(){
//    int n,m,v1,v2,temp;
//    scanf("%d %d",&n,&m);
//    for (int i=0; i< n; ++i) {
//        scanf("%d",&temp);
//        ma[temp]+=1;
//    }
//    for (int i=0; i<m; ++i) {
//        if(ma[i]){
//            ma[i]--;
//            if(ma[m-i] ){
//                printf("%d %d\n",i,(m-i));
//                return 0;
//            }
//            ma[i]++;
//        }
//    }
//    printf("No Solution\n");
//    return 0;
//}
