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

#define MAXIMUM_INT 100
#define MAXIMUM_INT_LENGTH 8

int lonelyinteger(vector < int > a)
{
    vector<int>::iterator itr = a.begin();
    bitset<MAXIMUM_INT_LENGTH> accumulator(0);
    while(itr != a.end()){
        bitset<MAXIMUM_INT_LENGTH> bin_element(*itr);
        accumulator ^= bin_element;
        ++itr;
    }
    return accumulator.to_ulong();
}

int main()
{
    int res;

    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++)
    {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = lonelyinteger(_a);
    cout << res;

    return 0;
}

