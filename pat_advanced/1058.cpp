#include <iostream>
using namespace std;
int main(){
  long long a,b,c,d,e,f;
  scanf("%lld.%lld.%lld %lld.%lld.%lld",&a,&b,&c,&d,&e,&f);
  long long sum=(a+d)*17*29+(b+e)*29+(c+f);
  long long G=sum/(17*29);
  sum=sum%(17*29);
  printf("%lld.%lld.%lld",G,sum/29,sum%29);
  return 0;
}
