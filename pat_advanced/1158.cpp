#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N=1005;
int k,b_k,n,m,e[N][N],tcal,trec,tdur，pres=0;
unordered_map<int,unordered_set<int>> v;
map<int,set<int>> ma;
set<int> suspect;
int main(){
    scanf("%d %d %d",&k,&n,&m);
    b_k=0.2*k;
    
    for(int i=0;i<m;++i){
        scanf("%d %d %d",&tcal,&trec,&tdur);
        v[tcal].insert(trec);
        e[tcal][trec]+=tdur;
    }    
    for(auto it=v.begin();it!=v.end();++it){
        int short_call=0,call_back=0;
        for(auto its=it->second.begin();its!=it->second.end();its++){
            if(e[it->first][*its]<=5){
                short_call++;
                if(e[*its ][it->first] >0) call_back++;    
            }
        } 
        if(short_call >k && call_back <=b_k)
            suspect.insert(it->first); 
    }
    if(suspect.size() ==0) {
        printf("None\n");
        return 0;
    }
    for(auto it=suspect.begin() ;it!=suspect.end();++it){
        if(e[pres][*it]>0&&e[*it][pres]>0){
            ma[pres].insert(*it);
        }else{
            ma[*it].insert(*it);
            pres=*it;
        }0
    }
    for(auto it=ma.begin() ;it!=ma.end();++it){
        for(auto its=it->second.begin();its!=it->second.end();its++)
            printf("%s%d",its!=it->second.begin() ?" ":"",*its);
        printf("\n");
    }
    return 0;
} 
