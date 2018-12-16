//
// 1022.cpp 
// pat 
// 
// Created by zerl on 2018/12/16. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 

#include <iostream>
#include <map>
#include <set>
using namespace std;
static map<string, set<int> > title, author,keywords ,publisher,year;


static void query(map<string, set<int> > &m,string &str){
    if (m.find(str) != m.end()) {
        for (auto it=m[str].begin(); it != m[str].end(); ++it)
//            cout << *it <<"\n";
            printf("%07d\n", *it);
    }else
        cout << "Not Found\n";
}


int i1022(){
    int n,m,tid,num;
    
    scanf("%d",&n);
    string ttitle,tauthor,tkeywords,tpublicer,tyear;
    for (int i=0; i<n; ++i) {

        scanf("%d\n",&tid);
        getline(cin, ttitle);
        title[ttitle].insert(tid);
        getline(cin, tauthor);//new
        author[tauthor].insert(tid);
        while (cin >> tkeywords) { // new{
            keywords[tkeywords].insert(tid);
            char c=getchar();
            if(c=='\n') break;
        }//}
        getline(cin, tpublicer);
        publisher[tpublicer].insert(tid);
        getline(cin, tyear);
        year[tyear].insert(tid);
    }
    scanf("%d",&m);
    for (int i=0; i<m; ++i) {
        scanf("%d: ",&num);
/*
 BAD:     1: The Testing Book  "1: "->("%d:",&num)  "The Testing Book"->(temp)
                                          ~^~
 format:  1: The Testing Book  "1: "->("%d: ",&num)  "The Testing Book"->(temp)
                                          ~^~
 同行格式输入 scanf() getline() 混用情况下  scanf应严格对照输入格式
 */
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num==1) query(title, temp);
        else if (num==2) query(author, temp);
        else if (num==3) query(keywords, temp);
        else if (num==4) query(publisher, temp);
        else if (num==5) query(year, temp);
    }
    return 0;
}


/*
 getline
*/
