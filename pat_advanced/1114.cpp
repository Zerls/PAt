//
// 1114.cpp
// pat
//
// Created by zerl on 2019/1/25.
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved.
//


/**
 题  意:
 给定每个 的家庭成员和其  名下的房产，请你统计出每个家庭的  数、 均房产  积及房产套数。
 先在第  输出家庭个数(所有有亲属关系的 都属于同 个家庭)。
 随后按下  格式输出每个家庭的信息:家庭成员的最 编号 家庭  数  均房产套数  均房产 积。其中 均 值要求保  数点后3位。
 家庭信息 先按 均 积降序输出，若有并 ，则按成员编号的升序输出。
 分析: 并查集。
 分别 两个结构体数组， 个data 来接收数据，接收的时候顺 实现 并查集的 操作union，另 个数组ans 来输出最后的答案，
 因为要计算家庭 数，所以 visit标记所有出现过 的结点，对于每个结点的 结点，people++统计 数。标记flag == true，
 计算true的个数cnt就可以知 道 共有多少个家庭。排序后输出前cnt个就是所求答案~~
 **/
#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA{
    int id,fid,mid,num,area;
    int cid[10];
}data[1005];
struct node_1114{
    int id,people;
    double num,area;
    bool flag = false;
}ans[10000];
static int father[10000];
static bool visit[10000];
static int find(int v){
    if(v==father[v]) return v;
    else{
        int F=find(father[v]);
        father[v]=F;
        return F;
    }
}
static void Union(int a,int b){
    int faA = find(a);
    int faB = find(b);

    if(faA >faB)
        father[faA] = faB;
    else if(faA < faB){
        father[faB] = faA;
    }
}

static int cmp1(node_1114 &a,node_1114 &b){
    if(a.area != b.area)
        return  a.area > b.area;
    else
        return  a.id < b.id;
}
int i1114(){
    int n,k,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<10000;i++)
        father[i]=i;
    for (int i=0; i<n; ++i) {
        scanf("%d %d %d %d",&data[i].id,&data[i].fid,&data[i].mid,&k);
        visit[data[i].id]=true;
        if(data[i].fid !=-1){
            visit[data[i].fid]=true;
            Union(data[i].fid,data[i].id);
        }
        if(data[i].mid !=-1){
            visit[data[i].mid]=true;
            Union(data[i].mid,data[i].id);
        }
        for (int j=0; j <k; ++j) {
            scanf("%d",&data[i].cid[j]);
            visit[data[i].cid[j]]=true;
            Union(data[i].cid[j],data[i].id);
        }
        scanf("%d %d",&data[i].num,&data[i].area);
    }
    for (int i = 0; i < n; ++i) {
        int id =find(data[i].id);
        ans[id].id=id;
        ans[id].num+=data[i].num;
        ans[id].area +=data[i].area;
        ans[id].flag=true;
    }
    for (int i=0; i<10000; ++i) {
        if(visit[i])
            ans[find(i)].people++;
        if(ans[i].flag)
            cnt++;
    }
    for (int i=0; i<10000; ++i) {
        if(ans[i].flag){
            ans[i].num =(double)(ans[i].num*1.0/ans[i].people);
            ans[i].area =(double)(ans[i].area *1.0/ans[i].people);
        }
    }
    sort(ans, ans+10000, cmp1);
    printf("%d\n",cnt);
    for (int i=0;i<cnt;i++) {
        printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
    }

    return 0;
}

