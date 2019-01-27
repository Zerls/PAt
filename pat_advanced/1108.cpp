#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/**
 分析:  
 用非常好用的sscanf和sprintf即可解决~
    sscanf() –从一个字符串中读进与指定格式相符的数据
    sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中
 **/
int main(){
    int n,cnt=0;
    double sum=0.0,temp;
    char a[50],b[50];
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        int flag=0;
        scanf("%s",a);
        sscanf(a, "%lf", &temp);//new!!
        sprintf(b, "%.2f",temp);//new!!
        for (int j=0; j<strlen(a); ++j) 
            if(a[j]!=b[j]) flag=1;
        if(flag==0 && temp >=-1000 && temp <= 1000){
            sum+=temp;
            cnt++;
        }else
            printf("ERROR: %s is not a legal number\n",a);
    }
    if(cnt==1){
        printf("The average of 1 number is %.2lf\n",sum);  
    }else if(cnt >1){
        printf("The average of %d numbers is %.2lf\n",cnt,sum/cnt);
    }else
        printf("The average of 0 numbers is Undefined\n");
    return 0;
}