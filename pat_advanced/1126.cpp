//
// 1126.cpp 
// pat 
// 
// Created by zerl on 2019/1/18. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
using namespace std;
static vector<vector<int>> v;
static bool visit[505];
static int obb_de,even_de;
static void dfs(int index){
    visit[index] =true;
    v[index].size() %2==0 ? even_de++ : obb_de++;
    for (int i=0; i<v[index].size(); ++i)
        if(visit[v[index][i]] ==false)
            dfs(v[index][i]);
}
int i1126(){
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    v.resize(n+1);
    for (int i=0; i<m; ++i) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for (int i=1; i<=n; ++i)
        printf("%d%s",(int)v[i].size(),(i!=n)?" ":"\n");
    if(obb_de==2 && even_de == n-2)
        printf("Semi-Eulerian\n");
    else if (even_de ==n)
        printf("Eulerian\n");
    else
        printf("Non-Eulerian\n");
    return 0;
}

//#include <iostream>
//#include <vector>
//using namespace std;
//static vector<vector<int>> v;
//static bool visit[505];
//static int obb_de,even_de;
//static void dfs(int index){
//    visit[index] =true;
//    v[index].size() %2==0 ? even_de++ : obb_de++;
//    for (int i=0; i<v[index].size(); ++i)
//        if(visit[v[index][i]] ==false)
//            dfs(v[index][i]);
//}
//int main(){
//    int n,m,a,b,cnt=0;
//    scanf("%d %d",&n,&m);
//    v.resize(n+1);
//    for (int i=0; i<m; ++i) {
//        scanf("%d %d",&a,&b);
//        v[a].push_back(b);
//        v[b].push_back(a);
//    }
//    for (int i=1; i<=n; ++i) {
//        if(visit[i] ==false){
//            dfs(i);
//            cnt++;
//        }
//    }
//    for (int i=1; i<=n; ++i)
//        printf("%d%s",(int)v[i].size(),(i!=n)?" ":"\n");
//    if(cnt ==1){
//        if(obb_de==2 && even_de == n-2)
//            printf("Semi-Eulerian\n");
//        else if (even_de ==n)
//            printf("Eulerian\n");
//        else
//            printf("Non-Eulerian\n");
//    }else
//        printf("Non-Eulerian\n");
//    return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//static vector<vector<int>> v;
//static bool visit[505];
//static int obb_de,even_de;
//static void dfs(int index){
//    visit[index] =true;
//    v[index].size() %2==0 ? even_de++ : obb_de++;
//    for (int i=0; i<v[index].size(); ++i)
//        if(visit[v[index][i]] ==false)
//            dfs(v[index][i]);
//}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<vector<int> > v;
//vector<bool> visit;
//int cnt = 0,n, m, a, b, even = 0;
//void dfs(int index) {
//    visit[index] = true;
//    cnt++;
//    for (int i = 0; i < v[index].size(); i++)
//        if (visit[v[index][i]] == false)
//            dfs(v[index][i]);
//}
//int main() {
//    scanf("%d%d", &n, &m);
//    v.resize(n + 1);
//    visit.resize(n + 1);
//    for (int i = 0; i < m; i++) {
//        scanf("%d%d", &a, &b);
//        v[a].push_back(b);
//        v[b].push_back(a);
//    }
//    for (int i = 1; i <= n; i++) {
//        printf("%d%s",(int)v[i].size(),(i!=n)?" ":"\n");
//        if (v[i].size() % 2 == 0) even++;
//    }
//    dfs(1);
//    if (even == n && cnt == n)
//        printf("Eulerian");
//    else if(even == n - 2 && cnt == n)
//        printf("Semi-Eulerian");
//    else
//        printf("Non-Eulerian");
//    return 0;
//}
