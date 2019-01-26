#include "pat_advanced.h"
#include<iostream>
using namespace std;

int i1001() {
    int a,b;
    cin >> a >> b;
    string s = to_string(a + b);
    long long len = s.length();
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
    }
    return 0;
}
