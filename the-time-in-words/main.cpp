#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<int, string> dictionary;

void initialize_map(){
        dictionary.insert(pair<int, string>(1, "one"));
        dictionary.insert(pair<int, string>(2, "two"));
        dictionary.insert(pair<int, string>(3, "three"));
        dictionary.insert(pair<int, string>(4, "four"));
        dictionary.insert(pair<int, string>(5, "five"));
        dictionary.insert(pair<int, string>(6, "six"));
        dictionary.insert(pair<int, string>(7, "seven"));
        dictionary.insert(pair<int, string>(8, "eight"));
        dictionary.insert(pair<int, string>(9, "nine"));
        dictionary.insert(pair<int, string>(10, "ten"));
        dictionary.insert(pair<int, string>(11, "eleven"));
        dictionary.insert(pair<int, string>(12, "twelve"));

        dictionary.insert(pair<int, string>(13, "thirteen"));
        dictionary.insert(pair<int, string>(14, "fourteen"));
        dictionary.insert(pair<int, string>(15, "quarter"));
        dictionary.insert(pair<int, string>(16, "sixteen"));
        dictionary.insert(pair<int, string>(17, "seventeen"));
        dictionary.insert(pair<int, string>(18, "eighteen"));
        dictionary.insert(pair<int, string>(19, "nineteen"));

        dictionary.insert(pair<int, string>(20, "twenty"));
        dictionary.insert(pair<int, string>(21, "twenty one"));
        dictionary.insert(pair<int, string>(22, "twenty two"));
        dictionary.insert(pair<int, string>(23, "twenty three"));
        dictionary.insert(pair<int, string>(24, "twenty four"));

        dictionary.insert(pair<int, string>(25, "twenty five"));
        dictionary.insert(pair<int, string>(26, "twenty six"));
        dictionary.insert(pair<int, string>(27, "twenty seven"));
        dictionary.insert(pair<int, string>(28, "twenty eight"));
        dictionary.insert(pair<int, string>(29, "twenty nine"));
        dictionary.insert(pair<int, string>(30, "half"));
}

void print_time(int h , int m){
    if( m == 0)
        cout << dictionary[h] << " o' clock";
    else if ( m == 15)
        cout << dictionary[m] << " past " << dictionary[h];
    else if ( m == 30)
        cout << dictionary[m] << " past " << dictionary[h];
    else if ( m == 45)
        cout << dictionary[60 - m] << " to " << dictionary[h + 1];
    else if ( m < 30)
        cout << dictionary[m] << " minutes past " << dictionary[h];
    else
        cout << dictionary[60 - m] << " minutes to " << dictionary[h + 1];
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int h, m;
    cin >> h >> m;
    initialize_map();
    print_time(h, m);
    return 0;
}
