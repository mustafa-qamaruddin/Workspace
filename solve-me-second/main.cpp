#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solve_me_second(int a, int b){
    return a + b;
}

int main()
{
    int num1, num2;
    int sum;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> num1 >> num2;
        sum = solve_me_second(num1, num2);
        cout << sum << endl;
    }
    return 0;
}
