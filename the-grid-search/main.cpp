#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char** grid;
char** pattern;

void print_matrix(char** m, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void grid_search(int r, int c, int pr, int pc){
    for(int i = 0;i < r; i++){
        for(int j = 0; j < c; j++){
            int found = 0;
            int k = 0, l = 0;
            while(k < pr && grid[i + k][j + l] == pattern[k][l]){
                found++;
                l = ( l + 1 ) % pc;
                if(l == 0)
                    k++;
            }
            if(found == (pr * pc)){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, r, c, pr, pc;
    cin >> t;
    while(t--){
            cin >> r >> c;
            grid = new char*[r];
            for(int i = 0; i < r; i++){
                grid[i] = new char[c];
                for(int j = 0; j < c; j++){
                    cin >> grid[i][j];
                }
            }
            cin >> pr >> pc;
            pattern = new char*[pr];
            for(int i = 0; i < pr; i++){
                pattern[i] = new char[pc];
                for(int j = 0; j < pc; j++){
                    cin >> pattern[i][j];
                }
            }
            grid_search(r, c, pr, pc);
    }
    return 0;
}
