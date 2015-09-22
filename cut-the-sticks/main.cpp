#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000

int a[MAX_N];

void print_all(vector<int> v){
    cout << endl;
    vector<int>::iterator itr = v.begin();
    while(itr != v.end()){
        cout << *itr << ", ";
        ++itr;
    }
    cout << endl;
}

void cut_the_sticks(int n)
{
    vector<int> v (a, a + n);
    sort(v.begin(), v.end());
    int acc_reduce = v[0];
    cout << n << endl;
    for(int i = 0;i < n; i++){ // O(N)
        v[i] -= acc_reduce;
        if(v[i] != 0)
            cout << n - i << endl;
        acc_reduce += v[i];
        v[i] -= v[i];
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cut_the_sticks(n);
    return 0;
}
