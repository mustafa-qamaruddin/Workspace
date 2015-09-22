#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

char** map;

void print_map(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void cavity_map(int n)
{
    for(int i = 1; i < n - 1; i++)
        for(int j = 1; j < n - 1; j++)
            if(map[i][j] > map[i+1][j]
                    && map[i][j] > map[i-1][j]
                    && map[i][j] > map[i][j+1]
                    && map[i][j] > map[i][j-1])
                map[i][j] = 'X';
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    map = new char*[n];
    for(int i = 0; i < n; i++)
        map[i] = new char[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    cavity_map(n);
    print_map(n);
    return 0;
}
