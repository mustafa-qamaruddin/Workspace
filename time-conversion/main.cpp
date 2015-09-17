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
    string ret = "", parts[4], hours;

    int i = 0;
    size_t pos;
    while(in.size() > 0)
    {

        pos = in.find(':');
        if(pos != string::npos)
        {
            parts[i] = in.substr(0, pos);
            in = in.substr(pos + 1);
        }
        else
        {
            parts[i] = in;
            in = "";
        }


        string temp = parts[i];

        size_t day_pos = temp.find("AM");
        if(day_pos != string::npos){ // 12:40:22AM -> 00:40:22
            if(parts[0] == "12"){
                parts[0] = "00";
            }
            parts[i] = temp.substr(0, day_pos);
        }

        size_t night_pos = temp.find("PM");
        if(night_pos != string::npos)
        {
            parts[i] = temp.substr(0, night_pos);
            if(parts[0].find("12") == string::npos) // 01PM, 02PM, 03PM, 04PM, 05PM, 06PM, 07PM, 08PM, 09PM, 10PM, 11PM
            {
                const char* char_arr = parts[0].c_str();
                int digit_0 = char_arr[0] - '0';
                int digit_1 = char_arr[1] - '0';
                int hours = digit_1 + 10 * digit_0+ 12;
                parts[0] = to_string(hours);
            }
        }

        if(day_pos == string::npos && night_pos == string::npos && parts[0] == "00") // 00:00:00
            parts[i] = parts[i]; // dummy assignment; just to flag this special case

        i++;

    }

    for(int i =0 ; i < 3; i++)
    {
        ret += parts[i];
        if(i != 2)
        {
            ret += ":";
        }
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
