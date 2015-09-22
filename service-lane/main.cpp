#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int widths[MAX_N];

int service_lane(int i, int j){
    int ret = widths[i];
    for(int k = i; k <= j; k++){
        if(widths[k] < ret)
            ret = widths[k];
    }
    return ret;
}

int main()
{
    int n, t, i, j;
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> widths[i];
    }
    while(t--){
        cin >> i >> j;
        cout << service_lane(i, j) << endl;
    }
    return 0;
}
