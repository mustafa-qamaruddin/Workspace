#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long tmp, sum = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
    }
    cout << sum;
    return 0;
}

