#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char** a;

void print_matrix(int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void acm_icpc_team(int n, int m)
{
    int global_max = -1, local_count, number_of_teams = 0;
    for(int i = 0;i < n; i++){

        for(int j = i+1; j < n; j++){
            local_count = 0;
            for(int k = 0; k < m; k++){
                if(a[i][k] == '1' || a[j][k] == '1')
                    local_count++;
            }
            if(local_count > global_max){
                global_max = local_count;
                number_of_teams = 1;
            }else if(local_count == global_max){
                number_of_teams++;
            }
        }
    }
    cout << global_max << endl;
    cout << number_of_teams << endl;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    a = new char*[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = new char[m];
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    acm_icpc_team(n, m);
    return 0;
}
