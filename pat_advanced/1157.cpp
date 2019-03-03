//解题一 
#include <iostream> 
#include <map> 
using namespace std; 
string maxs,maxalus,s1; 
int n,m,maxn=0x3fffffff,num=0,maxalu=0x3fffffff; 
map<string,int> ma; 
int main(){ 
    scanf("%d",&n);  
    for(int i=0;i<n;i++){     
        cin >> s1;
        ma[s1]=1;
    }  
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        cin >> s1;
        int aa=stoi(s1.substr(6,8));
      	if(maxn> aa){
            maxn=aa;
            maxs=s1;
        }
        if(ma[s1]==1)
           num++;
           if(maxalu> aa){
                maxalu=aa;
                maxalus=s1;             
            }
        }
    }
    if(num>=1){
        cout << num << "\n" <<maxalus <<"\n";
    }else
        cout <<"0\n"<< maxs <<"\n";
    return 0;
}

//解题二 
#include <iostream> 
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std; 
struct node{string s; }; 
bool cmp1(node &a, node &b){  
    int a1=stoi(a.s.substr(6,8));  
    int b1=stoi(b.s.substr(6,8)); 
    return a1  < b1; 
} 
string maxs,s1; 
int n,m,maxn=0x3fffffff; 
vector<node> v; 
map<string,int> ma; 
int main(){   
    scanf("%d",&n);  
    for(int i=0;i<n;i++){     
        cin >> s1;
        ma[s1]=1;
    }  
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        cin >> s1;
        if(ma[s1]==1) v.push_back(node{s1});
        int aa=stoi(s1.substr(6,8));
       if(maxn> aa){
            maxn=aa;
            maxs=s1;
        }
    }
    sort(v.begin(),v.end(),cmp1);
    if(v.size()>=1){
        cout << (int)v.size() << "\n" <<maxs <<"\n";
    }else
        cout <<"0\n"<< maxs <<"\n";
    return 0;
}
