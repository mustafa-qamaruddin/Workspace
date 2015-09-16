#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int sum = 0;
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
    }
    cout << sum;
    return 0;
}
