#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

int dp[1000][2];

void bt(int i, int n, int a, int b, int step, int sofar, set<int> &ret){
    dp[i][step] = sofar;
    if(i == 1){
        ret.insert(sofar);
        return;
    }
    if(dp[i-1][0] == 0)
        bt(i-1, n, a, b, 0, sofar + a, ret);
    if(dp[i-1][1] == 0)
        bt(i-1, n, a, b, 1, sofar + b, ret);
    return;
}

set<int> manasa_and_stone(int n, int a, int b){
    set<int> ret;
    bt(n, n, a, b, 0, 0, ret);
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, a, b;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        memset(dp, 0, 1000 * 2);
        set<int> result = manasa_and_stone(n, a, b);

        set<int>::iterator itr = result.begin();
        while(itr != result.end())
            cout << *itr++ << " ";
        cout << endl;
    }
    return 0;
}
