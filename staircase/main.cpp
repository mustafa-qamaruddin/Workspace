#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void draw_stair_case(int h){
    for(int i = 0; i < h; i++){
        for(int j = h - i - 1; j > 0; j--){
            cout << " ";
        }
        for(int j = 0; j <= i; j++){
            cout << "#";
        }
        cout << endl;
    }
}

int main()
{
    int height;
    cin >> height;
    draw_stair_case(height);
    return 0;
}
