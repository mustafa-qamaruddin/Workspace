#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void print_vector(vector<int> ar){
    vector<int>::iterator itr = ar.begin();
    while(itr != ar.end())
    {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
}

void insertionSort(vector <int>  ar)
{
    int sz = ar.size();
    vector<int>::reverse_iterator r_itr = ar.rbegin();
    int x = *r_itr;
    ++r_itr;
    while(r_itr != ar.rend() && x < *r_itr){
        vector<int>::reverse_iterator temp = r_itr - 1;
        *temp = *r_itr;
        print_vector(ar);
        ++r_itr;
    }
    *(r_itr-1) = x;
    print_vector(ar);
}

int main(void)
{
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++)
    {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    insertionSort(_ar);

    return 0;
}
