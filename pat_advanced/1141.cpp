//
// 1141.cpp 
// pat 
// 
// Created by zerl on 2019/1/15. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;
struct Node{
    string school;
    int tws,ns;
};
static bool cmp1(Node a ,Node b){
    if(a.tws !=b.tws)
        return a.tws >b.tws;
    else if(a.ns !=b.ns)
        return a.ns  < b.ns; // return a.ns  >  b.ns;
    else
        return a.school < b.school;
}

int i1141(){
    int n;
    double score;
    scanf("%d",&n);
    string school,id;
    unordered_map<string, double> cnt,sum;
    for (int i=0; i<n; ++i) {
        cin >> id >> score >> school;
        for (int j=0; j<school.size(); ++j)  school[j] =tolower(school[j]);
        if(id[0]=='B')
            score/=1.5;
        else if(id[0]=='T')
         score*=1.5;
        sum[school]+=score;
        cnt[school]++;
    }
    vector<Node> v;
    for (auto it=cnt.begin(); it!=cnt.end(); ++it)
        v.push_back(Node{it->first,(int)sum[it->first],(int)cnt[it->first]});
    sort(v.begin(), v.end(), cmp1);
    printf("%d\n",(int)v.size());
    int rank=0,pres=-1;
    for (int i=0; i< v.size(); ++i) {
        if(pres!=v[i].tws) rank=i+1;
        pres=v[i].tws;
        printf("%d ",rank);
        cout << v[i].school;
        printf(" %d %d\n",v[i].tws,v[i].ns);
    }
    return 0;
}
