#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

string time_conversion(string in)
{
    string ret, parts[4], hours;
    size_t pos = in.find(':');
    int i = 0;
    while(in.size() > 0)
    {
        parts[i] = in.substr(0, pos);
        if( pos != string::npos)
            in = in.substr(pos + 1);
        else
            in = "";

        string temp = parts[i];
        size_t day_night_pos = temp.find("AM");
        if(day_night_pos != string::npos)
        {
            parts[i] = temp.substr(0, day_night_pos);
        }

        day_night_pos = temp.find("PM");
        if(day_night_pos != string::npos)
        {
//            parts[i] = temp.substr(0, day_night_pos);
            if(parts[0].find('12') == string::npos) // 01PM, 02PM, 03PM, 04PM, 05PM, 06PM, 07PM, 08PM, 09PM, 10PM, 11PM
            {
//                const char* char_arr = parts[0].c_str();
//                int digit_0 = char_arr[0] - '0';
//                int digit_1 = char_arr[1] - '0';
//                int hours = digit_0 + 10 * digit_1;
//                cout << hours + 12 << endl;
            }
        }
    }

    pos = in.find(':');
    i++;

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
