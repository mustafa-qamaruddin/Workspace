#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int actual_d, actual_m, actual_y,
        expected_d, expected_m, expected_y;
    cin >> actual_d >> actual_m >> actual_y >> expected_d >> expected_m >> expected_y;
    if(actual_y - expected_y > 0){
        cout << 10000;
    }else if(actual_y - expected_y == 0){
        if( actual_m - expected_m > 0 ){
            cout << 500 * (actual_m - expected_m);
        }else if(actual_m - expected_m == 0){
            if(actual_d - expected_d > 0){
                cout << 15 * (actual_d - expected_d);
            }else{
                cout << 0;
            }
        }else{
            cout << 0;
        }
    }else{
        cout << 0;
    }
    return 0;
}
