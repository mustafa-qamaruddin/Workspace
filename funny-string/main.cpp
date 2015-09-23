#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 10000

bool is_funny(string s)
{
    int sz = s.length();
    for(int i = 1; i < sz; i++)
    {
        if(abs(s[i] - s[i-1]) !=
                abs(s[sz - i] - s[sz-i-1]))
            return false;
    }
    return true;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--)
    {
        char a[MAX_N];
        scanf("%s", a);
        string s(a);
        bool b = is_funny(s);
        if(b)
            cout << "Funny" << endl;
        else
            cout << "Not Funny" << endl;
    }
    return 0;
}
