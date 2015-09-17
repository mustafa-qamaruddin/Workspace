#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t, n, k, a, cnt;
    cin >> t;
    while(t--)
    {
        cnt = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            if( a <= 0)
            {
                cnt++;
            }
        }
        if(cnt < k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
