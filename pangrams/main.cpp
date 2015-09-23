#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_SZ 1000

char a[MAX_SZ];
bool flags[26];


void is_pangram(string s){
    string::iterator itr = s.begin();
    while(itr != s.end()){
        cout << *itr << endl;
        ++itr;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%s", a);
    string s(a);
    is_pangram(s);
    return 0;
}
