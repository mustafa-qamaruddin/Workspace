#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef pair<char, int> pci;
typedef map<char, int> mci;

mci freq_letters;

void calculate_frequency(string s)
{
    set<char> dont_repeat_chars; // local to this string
    for(int i = 0; i < s.length(); i++)  // O(N)
    {
        mci::iterator itr = freq_letters.find(s[i]); // O(lgN)
        set<char>::iterator s_itr = dont_repeat_chars.find(s[i]); // O(lgN)
        if(itr == freq_letters.end())
        {
            freq_letters.insert(itr, pci(s[i], 1)); // O(lgN) ~ O(1) as already  places the new node in place of itr ;)
            dont_repeat_chars.insert(s_itr, s[i]); // O(lgN) ~ O(1) as already  places the new node in place of itr ;)
        }
        else if (s_itr == dont_repeat_chars.end())   // it isn't repeated for this string
        {
            dont_repeat_chars.insert(s_itr, s[i]); // O(lgN) ~ O(1) as already  places the new node in place of itr ;)
            itr->second++;
        }
        else
            continue; // ignore
    }
}

int find_gems(int n)
{
    int ret = 0;
    mci::iterator itr = freq_letters.begin();
    while(itr != freq_letters.end())
    {
        if(itr->second == n)
            ret++;
        ++itr;
    }
    return ret;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        calculate_frequency(s);
    }
    cout << find_gems(n);
    return 0;
}
