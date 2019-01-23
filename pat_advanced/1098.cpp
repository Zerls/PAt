//
// 1098.cpp 
// pat 
// 
// Created by zerl on 2019/1/23. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> a,b;
static void downAdjust(int low, int high) {
    int i=1,j=i*2;
    while (j<=high) {
        if(j+1 <=high && b[j]<b[j+1]){//if(a[j]<=a[j+1]){
            j+=1;
        }
        if(b[i]<b[j+1]){
            swap(b[i], b[j]);
            i=j;j=i*2;
        }else{
            break;
        }
    }
}
int i1098(){
    int n,i,j;
    scanf("%d",&n);
    a.resize(n+1);
    b.resize(n+1);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    for (int i=1; i<=n; ++i)
        scanf("%d",&b[i]);
    for(i=2;i<=n && b[i-1]<=b[i];++i); //☆☆☆   题目问题 实际单增不减 It is assumed that the target sequence is always ascending.
    for(j=i;j<=n &&a[j]==b[j];++j);
    printf("%s",(j==n+1)? "Insertion Sort\n":"Heap Sort\n");
    if(j==n+1){
        sort(b.begin()+1, b.begin()+i+1);
    }else{
        
        int p=n;
        while (p>=2 && b[p]>=b[p-1]) p--;
        swap(b[1], b[p]);
        downAdjust(1, p-1);
    }
    for (int i=1; i<=n; ++i)
        printf("%d%s",b[i],(i!=n)?" ":"\n");
    return 0;
}


//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//static vector<int> a,b;
//static void downAdjust(int low, int high) {
//    int i = 0, j = i * 2+1;
//    while(j <= high) {
//        if(j + 1 <= high && b[j] < b[j + 1])
//            j = j + 1;
//        if(b[i] < b[j]) {
//            swap(b[i], b[j]);
//            i = j; j = i * 2+1;
//        } else {
//            break;
//        }
//
//    }
//
//}
//int main(){
//    int n,i,j;
//    scanf("%d",&n);
//    a.resize(n);
//    b.resize(n);
//    for (int i=0; i<n; ++i)
//        scanf("%d",&a[i]);
//    for (int i=0; i<n; ++i)
//        scanf("%d",&b[i]);
//    for(i=0;i<n-1 && b[i]<=b[i+1];++i);// for(i=1;i<n && b[i-1]<=b[i];++i); //☆☆☆
//    for(j=i+1;j<n &&a[j]==b[j];++j);
//    printf("%s",(j==n)? "Insertion Sort\n":"Heap Sort\n");
//    if(j==n){
//        sort(b.begin(), b.begin()+i+2);
//    }else{
//
//        int p = n-1;
//        while(p >= 1 && b[p] >= b[p - 1]) p--;
//        swap(b[0], b[p]);
//        downAdjust(0, p - 1);
//    }
//    for (int i=0; i<n; ++i)
//        printf("%d%s",b[i],(i!=n-1)?" ":"\n");
//    return 0;
//}
