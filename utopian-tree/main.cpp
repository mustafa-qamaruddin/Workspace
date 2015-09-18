#include <iostream>
using namespace std;

int height(int n) {
    int ret = 1;
    for(int i = 0;i < n; i++){
        if(ret % 2 == 0){
            ret += 1;
        }else{
            ret *= 2;
        }
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
