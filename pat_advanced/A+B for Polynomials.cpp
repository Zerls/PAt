#include "pat_advanced.h"
#include <iostream>
#include <map>
using namespace std;

map<int,double> polys;
//map<int,double>::reverse_iterator iter;

int i1002(){
    int in_count,exp;
    double coe;

    cin >> in_count;
    while (in_count--) {
        cin >> exp >> coe;
        polys[exp]=coe;
    }
    cin >> in_count;
    while (in_count--) {
        cin >> exp >> coe;
        polys.count(exp)==1 ? polys[exp]+=coe : polys[exp]=coe;
        polys[exp]==0?polys.erase(exp):0;
    }
    cout << polys.size();
    for( auto iter = polys.rbegin() ; iter !=polys.rend();iter++)
        printf(" %d %.1lf",iter->first,iter->second);
    cout<<endl;
    return 0;
}
