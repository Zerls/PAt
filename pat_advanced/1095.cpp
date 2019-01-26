//
// 1095.cpp 
// pat 
// 
// Created by zerl on 2019/1/23. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
struct node{
    string id;
    int time,flag=0;
};
static bool cmp1(node &a,node &b){
    if(a.id!=b.id )
        return a.id<b.id ;
    else
        return a.time < b.time;
}
static bool cmp2(node &a,node &b){
    return a.time < b.time;
}

int i1095(){
    int n,k,maxtime = -1,tempindex=0;
    scanf("%d%d\n",&n,&k);
    vector<node> record(n),car;
    for (int i =0; i< n; ++i) {
        char temp[5];
        int h,m,s;
        record[i].id.resize(10);
        scanf("%s %d:%d:%d %s\n",&record[i].id[0],&h,&m,&s,temp);
        int temptime =h*3600+m*60+s;
        record[i].time = temptime;
        record[i].flag = strcmp(temp,"in") == 0? 1:-1;
    }
    sort(record.begin(), record.end(), cmp1);
    map<string,int> mapp;
    for (int i=0; i<n-1; ++i) {
        if(record[i].id==record[i+1].id
           && record[i].flag ==1
           && record[i+1].flag==-1){
            car.push_back(record[i]);
            car.push_back(record[i+1]);
            mapp[record[i].id] +=(record[i+1].time-record[i].time);
            maxtime=max(maxtime,mapp[record[i].id]);
        }
    }
    sort(car.begin(),car.end(),cmp2);
    vector<int> cnt(n);
    cnt[0] +=car[0].flag;
    for (int i=1; i<car.size(); ++i)
            cnt[i] =cnt[i-1]+car[i].flag;
    
    for (int i=0; i<k; ++i) {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        int j,temptime =h*3600+m*60+s;
        for (j=tempindex; j<car.size(); ++j) {
            if(car[j].time > temptime){
                printf("%d\n",cnt[j-1]);
                break;
            }else if(j==car.size()-1){
                printf("%d\n",cnt[j]);
            }
        }
        tempindex=j;
    }
    for (auto it=mapp.begin(); it!=mapp.end(); it++)
        if(it->second == maxtime) printf("%s ",it->first.c_str());
     printf("%02d:%02d:%02d",maxtime/3600,(maxtime %3600)/60,maxtime%60);
    return 0;
}

/**伪代码
 in->data(id,time,in/out)
 sortdata->(id>,time<)
 datadeal->vaild_data( a car in&out record success){
    record maxtime & maxtime_car_list
 }
 count->(car_num in  a car in/out_time)
 inquire->(car_num in a time)
 out <- maxtime_car_list,maxtime
**/


//#include <cstdio>
//#include <cstring>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//const int maxn = 10010;
//struct Car {
//    char id[8];    // 车牌号
//    int time;    // 记录的时刻，以秒为单位
//    char status[4];    // in或者out
//}all[maxn], valid[maxn];    // all记录所有记录，valid为有效记录
//int num = 0;    // 有效记录的条数
//map<string, int> parkTime;    // 车牌号->总停留时间
//// timeToInt将时间转换为以秒为单位
//int timeToInt(int hh, int mm, int ss) {
//    return hh * 3600 + mm * 60 + ss;
//}
//// 先按车牌号字典序从小到大排序，相同的按时间从小到大排序
//bool cmpByIdAndTime(Car a, Car b) {
//    if(strcmp(a.id, b.id)) return strcmp(a.id, b.id) < 0;
//    else return a.time < b.time;
//}
//// 按时间从小到大排序
//bool cmpByTime(Car a, Car b) {
//    return a.time < b.time;
//}
//int i1095() {
//    int n, k, hh, mm, ss;
//    scanf("%d%d", &n, &k);    // 记录数，查询数
//    for(int i = 0; i < n; i++) {
//        scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
//        all[i].time = timeToInt(hh, mm, ss);    // 转换为以秒为单位
//    }
//    sort(all, all + n, cmpByIdAndTime);    // 按车牌号和时间排序
//    int maxTime = -1;    // 最长总停留时间
//    for(int i = 0; i < n - 1; i++) {    // 遍历所有记录
//        if(!strcmp(all[i].id, all[i + 1].id) &&    // i和i+1是同一辆车
//           !strcmp(all[i].status, "in") &&    // i是in记录
//           !strcmp(all[i + 1].status, "out")) {    // i+1是out记录
//            valid[num++] = all[i];    // i和i+1是配对的，存入valid数组
//            valid[num++] = all[i + 1];
//            int inTime = all[i + 1].time - all[i].time;    // 此次停留时间
//            if(parkTime.count(all[i].id) == 0) {
//                parkTime[all[i].id] = 0;    // map中还没有这个车牌号，置零
//            }
//            parkTime[all[i].id] += inTime;    // 增加该车牌号的总停留时间
//            maxTime = max(maxTime, parkTime[all[i].id]);    // 更新最大总停留时间
//        }
//    }
//    sort(valid, valid + num, cmpByTime);    // 把有效记录按时间从小到大排序
//    // now指向不超过当前查询时间的记录，numCar为当前校园内车辆数
//    int now = 0, numCar = 0;
//    for(int i = 0; i < k; i++) {
//        scanf("%d:%d:%d", &hh, &mm, &ss);
//        int time = timeToInt(hh, mm, ss);
//        // 让now处理至当前查询时间
//        while(now < num && valid[now].time <= time) {
//            if(!strcmp(valid[now].status, "in")) numCar++;    // 车辆进入
//            else numCar--;    // 车辆离开
//            now++;    // 指向下一条记录
//        }
//        printf("%d\n", numCar);    // 输出该时刻校园内车辆数
//    }
//    map<string, int>::iterator it;    // 遍历所有车牌号
//    for(it = parkTime.begin(); it != parkTime.end(); it++) {
//        if(it->second == maxTime) {    // 输出所有最长总停留时间的车牌号
//            printf("%s ", it->first.c_str());
//        }
//    }
//    // 输出最长总停留时间
//    printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
//    return 0;
//}
