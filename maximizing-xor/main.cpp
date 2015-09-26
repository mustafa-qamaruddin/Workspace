#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define NUM_BITS 12 // 0 : 2^n-1

/*
 * Complete the function below.
 */
int maxXor(int l, int r)
{
    int ret = -1;
    bitset<NUM_BITS> b_l(l), b_r(r+1), i(l);
    while(i != b_r)
    {
        bitset<NUM_BITS> j(l);
        while(j != b_r)
        {
            bitset<NUM_BITS> xor_res = i ^ j;
            int long_res = xor_res.to_ulong();
            if(ret < long_res)
                ret = long_res;

            bitset<NUM_BITS> temp(j.to_ulong() + 1);
            j = temp;
        }
        bitset<NUM_BITS> temp(i.to_ulong() + 1);
        i = temp;
    }
    return ret;
}

int main()
{
    int res;
    int _l;
    cin >> _l;

    int _r;
    cin >> _r;

    res = maxXor(_l, _r);
    cout << res;

    return 0;
}
