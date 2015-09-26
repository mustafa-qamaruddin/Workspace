#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

/**
 * 0 1 10
 * 84266613096281243382112
 */

ull mod_fib(ull a, ull b, int n){
    ull* dp = new ull[n];
    dp[0] = a;
    dp[1] = b;
    for(int i = 2; i < n; i++){
        dp[i] = dp[i-1] * dp[i-1] + dp[i-2];
    }
    return dp[n-1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ull a, b;
    int n;
    cin >> a >> b >> n;
    cout << mod_fib(a,b,n);
    return 0;
}
