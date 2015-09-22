#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
Input:
12
Hello_World!
4

Output:
Lipps_Asvph!
**/
void caesar_cipher(char* in, int n, int k)
{
    for(int i = 0; i < n; i++)
    {
        bool L1 = (in[i] - 'A' >= 0 && 'Z' - in[i] >= 0 );
        bool L2 = (in[i] - 'a' >= 0 && 'z' - in[i] >= 0 );
        if(L1){
            in[i] = ((in[i] + k)-'A') % 26 + 'A';
        }else if(L2){
            in[i] = ((in[i] + k)-'a') % 26 + 'a';
        }
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n;
    char* in_str = new char[n+1];
    for(int i = 0; i < n; i++)
    {
        cin >> in_str[i];
    }
    in_str[n] = '\0';
    cin >> k;
    caesar_cipher(in_str, n, k);
    cout << in_str;
    return 0;
}
