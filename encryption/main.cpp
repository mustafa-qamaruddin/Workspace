#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <typeinfo>

using namespace std;

char** matrix;
string s;
int g_rows, g_cols;

void print_matrix()
{
    for(int i = 0; i < g_rows; i++)
    {
        for(int j = 0; j< g_cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void distill(int rows, int cols)
{
    matrix = new char*[rows];
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];
        for(int j = 0; j < cols; j++)
        {
            matrix[i][j] = s[i * cols + j];
        }
    }
    g_rows = rows;
    g_cols = cols;
}

/*
⌊√L⌋≤rows≤column≤⌈√L⌉, where ⌊x⌋ is floor function and ⌈x⌉ is ceil function
*/
void min_area()
{
    int l = s.length();
    double sqrt_l = sqrt(l);
    int floor_sqrt_l = floor(sqrt_l);
    int ceil_sqrt_l = ceil(sqrt_l);
    if(floor_sqrt_l* ceil_sqrt_l >= l)
        distill(floor_sqrt_l, ceil_sqrt_l);
    else
        distill(ceil_sqrt_l, ceil_sqrt_l);
}

void encrypt()
{
    for(int i = 0; i < g_cols; i++)
    {
        for(int j= 0; j < g_rows; j++)
        {
            cout << matrix[j][i];
        }
        cout << " ";
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    getline(cin, s);
    min_area();
    encrypt();
    return 0;
}
