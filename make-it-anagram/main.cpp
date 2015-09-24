#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_LEN 10000
#define ALPHABETS 26

int freq_a[ALPHABETS];
int freq_b[ALPHABETS];

// delete letters in a and not in b

// if letter found in a x times, and in b x + n times
// delete n letters from b

void calculate_frequencies(string s, int freqs[]){
    for(int i = 0;i < s.length(); i++){
        int index = s[i] - 'a';
        freqs[index] = freqs[index] + 1;
    }
}

int compare_freq(){
    int ret = 0;
    for(int i = 0; i < ALPHABETS; i++){
        if(freq_a[i] == freq_b[i])
            continue;
        ret += abs(freq_a[i] - freq_b[i]);
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    memset(freq_a, 0, ALPHABETS);
    memset(freq_b, 0, ALPHABETS);
    string a, b;
    cin >> a >> b;
    calculate_frequencies(a, freq_a);
    calculate_frequencies(b, freq_b);
    cout << compare_freq();
    return 0;
}
