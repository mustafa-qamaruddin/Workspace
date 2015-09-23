#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define MAX_SZ 1000
#define ALPHABETS 26
bool flags[ALPHABETS];


bool is_pangram(string s){
    for(int i = 0; i < s.length(); i++){
        if(tolower(s[i]) <= 'z' && tolower(s[i]) >= 'a'){
            flags[tolower(s[i]) - 'a'] = true;
        }
    }
    for(int i = 0; i < ALPHABETS; i++){
        if(flags[i] == false)
            return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    memset(flags, ALPHABETS, false);
    string s;
    getline(cin, s);
    bool x = is_pangram(s);
    if(x)
        cout << "pangram";
    else
        cout << "not pangram";
    return 0;
}
