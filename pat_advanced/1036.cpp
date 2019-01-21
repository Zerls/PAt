//
// 1036.cpp 
// pat 
// 
// Created by zerl on 2019/1/21. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
using namespace std;
struct node_1036{
    string name,id;
    int grade;
};
int i1036(){
    int n,tgrade;
    string tn,tg,tid;
    node_1036 girl={"","",-1},boy={"","",101};
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        cin >> tn >> tg >> tid >> tgrade;
        if(tg=="F" && tgrade >girl.grade)
            girl={tn,tid,tgrade};
        if(tg=="M" && tgrade <boy.grade)
            boy={tn,tid,tgrade};
    }
//    printf("%d %d\n",girl.grade,boy.grade);
    (girl.grade==-1) ? printf("Absent\n") : printf("%s %s\n",girl.name.c_str(),girl.id.c_str());
    (boy.grade==0x3fffffff) ? printf("Absent\n"):printf("%s %s\n",boy.name.c_str(),boy.id.c_str());
    (girl.grade==-1||boy.grade==0x3fffffff) ? printf("NA\n") : printf("%d\n",girl.grade-boy.grade);
    return 0;
}


//int main(){
//    int n,tgrade;
//    string tn,tg,tid;
//    node girl={"","",-1},boy={"","",101};
//    scanf("%d",&n);
//    for (int i=0; i<n; ++i) {
//        cin >> tn >> tg >> tid >> tgrade;
//        if(tg=="F" && tgrade >girl.grade)
//            girl={tn,tid,tgrade};
//        if(tg=="M" && tgrade <boy.grade)
//            boy={tn,tid,tgrade};
//    }
//    (girl.grade==-1) ? printf("Absent\n") : printf("%s %s\n",girl.name.c_str(),girl.id.c_str());
//    (boy.grade==101) ? printf("Absent\n"):printf("%s %s\n",boy.name.c_str(),boy.id.c_str());
//    (girl.grade==-1||boy.grade==101) ? printf("NA\n") : printf("%d\n",girl.grade-boy.grade);
//    return 0;
//}
