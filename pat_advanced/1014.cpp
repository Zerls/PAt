//
// 1014.cpp 
// pat 
// 
// Created by zerl on 2018/12/11. 
// Github: https://github.com/zerls
// Copyright © 2018年 zerl. All rights reserved. 
// 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node_0 {
    int poptime,endtime;
    queue<int> q;
};

int i1014(){
    int n,m,k,q,index=1;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    
    vector<int> time(k+1),result(k+1);
    for (int i=1; i<=k; ++i) { //i=1
        scanf("%d",&time[i]);
    }
    vector<node_0> windows(n+1);
    vector<bool> sorry(k+1,false);
    
    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            if(index <= k){
                windows[j].q.push(time[index]);
                if(windows[j].endtime >=540)
                    sorry[index]=true;
                windows[j].endtime +=time[index];
                if(i==1)
                    windows[j].poptime=windows[j].endtime;
                result[index]=windows[j].endtime;
                index++;
            }
        }
    }
    while(index <= k){
        int tempmin=windows[1].poptime,tempwindow=1;
        for (int i=2; i<=n; ++i) {
            if(windows[i].poptime < tempmin){
                tempmin=windows[i].poptime;
                tempwindow=i;
            }
        }
        windows[tempwindow].q.pop();
        windows[tempwindow].q.push(time[index]);
        windows[tempwindow].poptime += windows[tempwindow].q.front();
        if(windows[tempwindow].endtime >= 540)
            sorry[index]=true;
        windows[tempwindow].endtime +=time[index];
        result[index]=windows[tempwindow].endtime;
        index++;
    }
    for (int i=1; i<=q; ++i) {
        int query,minute;
        scanf("%d",&query);
        minute=result[query];
        if(sorry[query]==true)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n",(minute+480)/60,(minute+480)%60);
    }
    return 0;
}
