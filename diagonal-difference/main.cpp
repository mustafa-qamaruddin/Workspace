#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int diagonal_difference(int matrix[], int sz)
{
    int sum = 0;
    for(int i = 0; i < sz; i++)
    {
        sum += matrix[i + i * sz];
    }
    return sum;
}

int diagonal_difference_2(int matrix[], int sz)
{
    int sum = 0;
    for(int i = 0; i < sz; i++)
    {
        sum += matrix[((sz - i - 1) + (sz * i))];
    }
    return sum;
}

int main()
{
    int matrix[MAX * MAX];
    int n, sum1, sum2, diff;
    cin >> n;
    for(int i = 0; i < n * n; i++)
    {
        cin >> matrix[i];
    }
    sum1 = diagonal_difference(matrix, n);
    sum2 = diagonal_difference_2(matrix, n);
    diff = abs(sum2 - sum1);
    cout << diff;
    return 0;
}
