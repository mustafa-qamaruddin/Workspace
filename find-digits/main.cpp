#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
/*
Input:
11
123456789
114108089
110110015
121
33
44
55
66
77
88
106108048
Output:
3
3
6
2
2
2
2
2
2
2
5
*/
int find_digits(ll n){
    int ret = 0;
    ll original = n;
    while(n){
        int d = n % 10;
        if( d != 0 && original % d == 0 )
            ret++;
        n = n / 10;
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << find_digits(n) << endl;
    }
    return 0;
}
