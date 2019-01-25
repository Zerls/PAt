//
// 1033.cpp 
// pat 
// 
// Created by zerl on 2019/1/24. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static const int INF=0x3fffffff;
struct station{
    double price,dis;
};
static bool cmp1(station &a,station &b){
    return  a.dis < b.dis;
}

int i1033(){
    double cmax,d,davg;
    int n;
    scanf("%lf%lf%lf%d",&cmax,&d,&davg,&n);
    vector<station> sta(n+1);
    sta[0]={0.0,d};
    for(int i=1;i <=n ; i++) scanf("%lf%lf",&sta[i].price,&sta[i].dis);
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis=0.0,maxdis=0.0,nowprice =0.0,totalPrice = 0.0,leftdis = 0.0;
    if (sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }else{
        nowprice =sta[0].price;
    }
    while(nowdis < d){
        maxdis =nowdis+cmax*davg;
        double minPriceDis = 0,minPrice =INF;
        int flag=0;
        for(int i=1;i<=n && sta[i].dis <=maxdis;i++){
            if(sta[i].dis <=nowdis) continue;
            if(sta[i].price < nowprice){
                totalPrice +=(sta[i].dis-nowdis-leftdis) *nowprice /davg;
                leftdis=0.0;
                nowprice =sta[i].price;
                nowdis = sta[i].dis;
                flag=1;
                break;
            }
            if(sta[i].price < minPrice){
                minPrice =sta[i].price;
                minPriceDis =sta[i].dis;
            }
        }
        if(flag==0 && minPrice !=INF){
            totalPrice +=(nowprice*(cmax-leftdis/davg));
            leftdis =cmax*davg -(minPriceDis -nowdis);
            nowprice=minPrice;
            nowdis=minPriceDis;
        }
        if(flag==0 && minPrice ==INF){
            nowdis +=cmax*davg;
            printf("The maximum travel distance = %.2f",nowdis);
            return 0;
        }
    }
    printf("%.2f",totalPrice);
    return 0;
}


/**
 题  意:汽 从杭州出发可以通过 速公 去任何城市，但是油箱的容 是有限的， 上有很多加 油站，每个加油站的价格 同，为汽 设计 个从杭州到终点的最 宜的 线，
     Cmax表示油箱最 容  ，
     D表示杭州到 的地的距离，
     Davg表示平均每单位的汽油可以让汽  驶的距离，
     N表示汽 的站 点数 ，
     每个站点都会给出它的单位油价Pi和汽 站点和杭州的距离Di，
     求汽 从杭州到终点的最  花费，如果 能够到达，就输出汽 能够 驶的最 距离
 
 
 分析:贪 算法。
 0.假设增加 个 的地处的加油站，距离为 的地的距离，价格为0，考虑从0距离开始能否到达最后  个加油站的问题
 1.因为先开始没有油，所以如果所有的加油站距离都没有等于0的，那么说明 哪也去  ，直接输出 并return
 2.将加油站按照距离dis从 到 排序 3.先去第 个加油站，设置变 nowdis表示当前所在的距离，maxdis是能够到达的最 距离，
 nowprice是当前的站点的价格，totalPrice是总的价格。
 贪 思想:
 0.寻找   距离远的，到能够到达的最 距离之间的加油站，看他们的油价。如果找到  低价格 的油价，就加油到刚好能到达那个加油站的距离的油，然后去那个 低价格的加油站(有 低的我  分都 想多花在别的距离上，只加到刚好满  低价格的加油站的距离就 ，那样以后的 程我就可 以以 低的价格 驶啦)
 1.如果找 到 低的，就找尽可能低的油价的加油站，在当前加油站加满油之后过去。因为想要让  程上使 的尽可能是低价的油，既然没有 当前 低价格的 ，就让油箱加到最 值，这样能保证  益最 化，保证最 的距离使 的是 宜的油。
 
 **/
