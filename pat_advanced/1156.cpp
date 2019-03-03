#include <iostream>
#include <algorithm>
using namespace std;
bool isprime(int a){
	if(a<=1) return false;
	int sqr=sqrt(1.0*a);
	for(int i=2;i<=sqr;++i)
		if(a%i==0) return false;
	return true;
} 
int n,flag1=1,flag2=1,flag3=1;
int main(){
	scanf("%d",&n);
	if(!isprime(n)) flag1=0;
	if(!isprime(n-6)) flag2=0;
	if(!isprime(n+6)) flag3=0;
	if(flag1 && flag2) printf("Yes\n%d\n",n-6);
	else if(flag1 && flag3) printf("Yes\n%d\n",n);
	else{
		int c=n+1;
		while(!isprime(c)) c++;
		printf("No\n%d\n",c);
	}
	return 0;
} 
