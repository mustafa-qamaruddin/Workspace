#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define ALPHABETS 26

void calc_freq(string s, int i, int j, int* freq)
{
    for(int k = i; k < j; k++)
    {
        int index = s[k] - 'a';
        freq[index] = freq[index] + 1;
    }
}

int anagram(string s)
{
    int* freq_a = new int[ALPHABETS];
    int* freq_b = new int[ALPHABETS];
    memset(freq_a, 0, ALPHABETS * sizeof(int));
    memset(freq_b, 0, ALPHABETS * sizeof(int));
    int ret = 0;
    int sz = s.length();
    if(sz % 2 == 1)
        return -1;
    calc_freq(s, 0, sz / 2, freq_a);
    calc_freq(s, sz / 2, sz, freq_b);
    for(int i = 0; i < ALPHABETS; i++)
    {
        //cout << i << ", a:" << freq_a[i] << ", b:" << freq_b[i] << endl;
        if(freq_a[i] >= freq_b[i]) // avoids calculating diff twice
            continue;
        ret += abs(freq_a[i] - freq_b[i]);
    }
    delete[] freq_a;
    delete[] freq_b;
    return ret;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    freopen("test_case_1.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << anagram(s) << endl;
    }
    return 0;
}
