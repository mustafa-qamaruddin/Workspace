#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int min_dels(string s)
{
    int cnt = 0;
    for(int i = 0; i < s.length() - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            s.erase(s.begin() + i);
            cnt++;
            i--;
        }
    }
    return cnt;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--)
    {
        char a[100000];
        scanf("%s", a);
        string s(a);
        cout << min_dels(s) << endl;
    }
    return 0;
}
