#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_DIGITS 100

typedef unsigned long long ull;

int int_to_array(ull n, int arr[])
{
    int i = 0;
    while(n)
    {
        arr[i] = n % 10;
        n = n / 10;
        i++;
    }
    return i;
}

bool is_kaprekar(ull n)
{
    ull x = pow(n, 2);
    int arr[MAX_DIGITS];
    int sz = int_to_array(x, arr);

    ull l = 0;
    int p = 0;
    if(sz%2)
        for(int i = sz/2+1; i < sz; i++)
        {
            l += arr[i] * pow(10, p);
            p++;
        }
    else
        for(int i = sz/2; i < sz; i++)
        {
            l += arr[i] * pow(10, p);
            p++;
        }

    ull r = 0;
    p = 0;
    if(sz%2)
        for(int i = 0; i <= sz/2; i++)
        {
            r += arr[i] * pow(10, p);
            p++;
        }
    else
        for(int i = 0; i < sz/2; i++)
        {
            r += arr[i] * pow(10, p);
            p++;
        }

//cout << "l = " << l << " & r = " << r << endl;

    if( l + r == n)
        return true;
    else
        return false;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ull p, q;
    cin >> p >> q;
    int cnt = 0;
    for(ull i = p; i <= q; i++)
    {
        if(is_kaprekar(i))
        {
            cnt++;
            cout << i << " ";
        }

    }
    if(cnt == 0)
        cout << "INVALID RANGE" << endl;
    return 0;
}
