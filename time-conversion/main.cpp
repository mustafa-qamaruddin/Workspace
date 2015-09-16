#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string time_conversion(string in)
{
    string ret;
    size_t pos = in.find(':');
    while(pos != string::npos)
    {
        ret += in.substr(0, pos);
        in = in.substr(pos + 1);
        size_t pos = in.find(':');
    }
    return ret;
}

int main()
{
    string in_time, out_time;
    getline(cin, in_time);
    out_time = time_conversion(in_time);
    cout << out_time;
    return 0;
}
