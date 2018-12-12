//
// 1017.cpp 
// pat 
// 
// Created by zerl on 2018/12/12. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct customer_1017{
    int arrive,proces;
};
bool cmp_1017(const customer_1017 &a,const customer_1017 &b){
    return a.arrive<b.arrive;
}
int i1017(){
    int n,k;
    double total=0.0;
    const int bank_open_time=8*3600,bank_close_time=17*3600;
    
    scanf("%d%d",&n,&k);
    vector<int> windows_time(k,bank_open_time);
    vector<customer_1017> v;
    for (int i=0; i<n; ++i) {
        int hour,minute,second,temp;
        scanf("%d:%d:%d %d",&hour,&minute,&second,&temp);
        int time =hour*3600+minute*60+second;
        if(time > bank_close_time) continue;
        customer_1017 cus ={time,temp*60};
        v.push_back(cus);
    }
    
    sort(v.begin(), v.end(), cmp_1017);
    
    for (int i =0; i<v.size(); ++i) {
        int tempmin=0;
        for (int j=1; j<k; ++j) {
            if(windows_time[tempmin] > windows_time[j])
                tempmin=j;
        }
        if(windows_time[tempmin]< v[i].arrive){
            windows_time[tempmin]=v[i].arrive;
        }else
            total+=windows_time[tempmin]-v[i].arrive;
        windows_time[tempmin]+=v[i].proces;
    }
    
    v.size() == 0 ? printf("0.0") : printf("%.1f\n",total/60/v.size());  //P k n 不分
    
    return 0;
}
