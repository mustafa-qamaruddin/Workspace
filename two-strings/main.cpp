#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_LEN 100000

string a, b;

bool bt()
{
    set<char> freq;
    string::iterator itr_a = a.begin();
    while(itr_a != a.end())
    {
        freq.insert(*itr_a);
        ++itr_a;
    }

    string::iterator itr_b = b.begin();
    while(itr_b != b.end())
    {
        set<char>::iterator itr_s = freq.find(*itr_b);
        if(itr_s != freq.end())
            return true;
        ++itr_b;
    }

    return false;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(bt())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
