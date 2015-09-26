#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define NUM_BITS 32
typedef unsigned int uint32;

uint32 flipper(uint32 x){
    uint32 ret;
    bitset<NUM_BITS> bin_rep(x);
    bitset<NUM_BITS> temp = ~bin_rep;
    ret = temp.to_ulong();
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    uint i;
    cin >> t;
    while(t--){
        cin >> i;
        cout << flipper(i) << endl;
    }
    return 0;
}
