#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string w, next_smallest;

void permute(int sz, int pos, string acc)
{
    cout << sz << " " << pos << " " << acc << endl;
    if(pos == sz)
    {
        if(acc > w && acc < next_smallest)
        {
            cout << acc << endl;
            next_smallest = acc;
        }
        return;
    }
    for(int k = 0; k < sz; k++)
    {
        permute(sz, pos+1, acc + w[k]);
    }
    return;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--)
    {
        cin >> w;
        next_smallest = w;
        permute(w.length(), 0, "");
        cout << next_smallest << endl;
    }
    return 0;
}
