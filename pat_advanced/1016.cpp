//
// 1016.cpp 
// pat 
// 
// Created by zerl on 2018/12/11. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct node_1016 {
    string name;
    int status,time,month,day,hour,minute;
};

bool cmp_1016(const node_1016 &a,const node_1016 &b) {
    return a.name!=b.name ?  a.name<b.name : a.time<b.time ; //P
}

double bill(node_1016 & call,int rate[]){
    //计算从该时刻 -0:0:0的累积费用
    double fee =rate[call.hour]*call.minute + rate[24]*60*call.day;
    for (int i=0; i<call.hour; ++i)
        fee +=rate[i]*60;  //P
    return fee/100.0; //cent->$
}

int i1016(){
    int rate[25]={0},n;
    for (int i=0; i<24; ++i) {
        scanf("%d",&rate[i]);
        rate[24]+=rate[i];
    }
    cin >> n;
    vector<node_1016> data(n);
    for (int i=0 ; i < n ; ++i) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d",
              &data[i].month,
              &data[i].day,
              &data[i].hour,
              &data[i].minute);
        string temp;
        cin >>temp;
        data[i].status=(temp =="on-line") ? 1:0;
        data[i].time=data[i].day*24*60+data[i].hour*60+data[i].minute;
    }
    
    sort(data.begin(), data.end(), cmp_1016);
    map<string, vector<node_1016>> customer;
    for (int i=1; i<n; ++i) {
        if(data[i].name == data[i-1].name
            && data[i].status == 0
            && data[i-1].status == 1) {
                customer[data[i-1].name].push_back(data[i-1]);//P
                customer[data[i-1].name].push_back(data[i]);//P
        }
    }
    
    for (auto it: customer) {
        double total =0.0;
        vector<node_1016> temp =it.second;
        cout << it.first;
        printf(" %02d\n",temp[0].month);
        for (int i = 1; i<temp.size(); i+=2) {
            double t =bill(temp[i],rate)-bill(temp[i-1],rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                   temp[i-1].day,temp[i-1].hour,temp[i-1].minute,
                   temp[i].day,temp[i].hour,temp[i].minute,
                   temp[i].time-temp[i-1].time,t);
            total+=t;
        }
        printf("Total amount: $%.2f\n",total);
    }
    return 0;
}
