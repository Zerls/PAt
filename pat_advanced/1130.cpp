//
// 1130.cpp
// pat
//
// Created by zerl on 2019/1/17.
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved.
//

//#include <iostream>
//#include <cctype>
//#include <vector>
//using namespace std;
//struct Node{
//    string data;
//    int l,r;
//};
//static int root;
//static vector<Node> v;
//static bool nroot[25];
//static void dfs(int index){
//    int flag=0;
//    if(!isalnum(v[index].data[0]) && index !=root) flag=1;
//    if(flag==1) printf("(");
//    if(v[index].l !=-1) dfs(v[index].l);
//    cout << v[index].data ;
//    if(v[index].r !=-1) dfs(v[index].r);
//    if(flag==1) printf(")");
//}
//int i1130(){
//    int n ,a,b;
//    scanf("%d",&n);
//    v.resize(n+1);
//    string s;
//    for (int i=1; i<=n; ++i) {
//        cin >> s >> a>> b;
//        v[i]=Node{s,a,b};
//        nroot[a]=nroot[b]=true;
//    }
//    while(nroot[roor] ==true) root+=1;
//    dfs(root);
//    return 0;
//}
#include <iostream>
using namespace std;
struct node {
    string data;
    int l, r;
}a[100];
static string dfs(int root) {
    if(a[root].l == -1 && a[root].r == -1)
        return a[root].data;
    if(a[root].l == -1 && a[root].r != -1)
        return "(" +  a[root].data + dfs(a[root].r) + ")";
    if(a[root].l != -1 && a[root].r != -1)
        return "(" +  dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
    return "";
}
int i1130() {
    int have[100] = {0}, n, root = 1;
    cin >> n;
    for(int i  = 1; i <= n; i++) {
        cin >> a[i].data >> a[i].l >> a[i].r;
        if(a[i].l != -1) have[a[i].l] = 1;
        if(a[i].r != -1) have[a[i].r] = 1; //nroot[a]=nroot[b]=true;
    }
    while(have[root] == 1) root++;
    string ans = dfs(root);
    if(ans[0] == '(')
        ans = ans.substr(1,ans.size()-2);
    cout << ans;
    return 0;
}
