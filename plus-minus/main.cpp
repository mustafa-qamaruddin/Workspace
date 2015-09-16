#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int n, a;
    double ratio_positive, ratio_negative, ratio_zero;
    int count_positive = 0, count_negative = 0, count_zero = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(a < 0)
        {
            count_negative++;
        }
        else if(a > 0)
        {
            count_positive++;
        }
        else
        {
            count_zero++;
        }
    }

    ratio_positive = (double)count_positive / n;
    ratio_negative = (double)count_negative / n;
    ratio_zero = (double)count_zero / n;

    cout << fixed << setprecision(3);
    cout << ratio_positive << endl;
    cout << ratio_negative << endl;
    cout << ratio_zero << endl;

    return 0;
}
