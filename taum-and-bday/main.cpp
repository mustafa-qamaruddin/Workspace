#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull taum_and_bday(ull b, ull w, ull x, ull y, ull z){
        ull sum = 0;

        if( w * y < w * x + w * z)
            sum += w * y;
        else
            sum += w * x + w * z;

        if( b * x < b * y + b * z)
            sum += b * x;
        else
            sum += b * y + b * z;

        return sum;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ull t, b, w, x, y, z;
    cin >> t;
    while(t--)
    {
        cin >> b >> w >> x >> y >> z;
        ull sum = taum_and_bday(b, w, x, y, z);
        cout << sum << endl;
    }
    return 0;
}
