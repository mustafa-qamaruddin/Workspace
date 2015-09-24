#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef map<char, int> mci;
mci freq;
mci current_occurences;

bool is_palindrome(){
    int odd_freq = 0;
    mci::iterator itr = freq.begin();
    while(itr != freq.end())
    {
        if(itr->second % 2 != 0)
            odd_freq++;
        itr++;
    }
    if(odd_freq > 1)
        return false;
    else
        return true;
}

bool is_palindrome(string s)
{
    int sz = s.length();
    for(int i = 0; i < sz / 2; i++)
    {
        if(s[i] != s[sz-i-1])
            return false;
    }
    return true;
}

bool permutations(int sz, int start, string rem, string sofar, set<char> taken_chars)
{
    if(start == sz)
    {
        if(is_palindrome(sofar))
            return true;
    }
    for(int i = start; i < sz; i++)
    {
        mci::iterator co_itr = current_occurences.find(rem[i]);
        mci::iterator f_itr = freq.find(rem[i]);
        if(co_itr == current_occurences.end()) // first occurence
            current_occurences.insert(pair<char, int>(rem[i], 1));
        else if(co_itr->second >= f_itr->second) // already used n times as in original string
            continue;
        else
        {
            taken_chars.insert(rem[i]);
            if(permutations(sz, start + 1, rem, sofar + rem[i], taken_chars))
                return true;
        }
    }
    return false;
}

void calc_freq(string s)
{
    for(int i = 0; i < s.length(); i++)  // O(N)
    {
        mci::iterator itr = freq.find(s[i]);
        if(itr != freq.end()) // O(lgN)
            itr->second++;
        else
            freq.insert(itr, pair<char, int>(s[i], 1));
    }
}

void print_map()
{
    mci::iterator itr = freq.begin();
    while(itr != freq.end())
    {
        cout << itr->first << " -> " << itr->second << endl;
        itr++;
    }
}

int main()
{

    string s;
    cin>>s;

    set<char> taken;
    calc_freq(s);
//    bool flag = permutations(s.length(), 0, s, "", taken);
    bool flag = is_palindrome();
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
