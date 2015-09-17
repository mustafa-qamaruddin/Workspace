#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

struct decents {
    int n_3s = 0, n_5s = 0;
    ll v = 0;
};

ll is_decent(decents x){
    if(x.n_3s % 5 == 0 && x.n_5s % 3 == 0)
        return x.v;
    else
        return -1;
}

ll bt(int n){
    queue<decents> delta;
    decents d, k1, k2;;
    delta.push(d);
    for(int i = 0; i < n; i++){
        size_t sz = delta.size();
        while(sz--){
            decents x = delta.front();
            delta.pop();
            k1.v = x.v + 3 * pow(10, i);
            k1.n_3s = x.n_3s + 1;
            k1.n_5s = x.n_5s;
            delta.push(k1);

            k2.v = x.v + 5 * pow(10, i);
            k2.n_3s = x.n_3s;
            k2.n_5s = x.n_5s + 1;
            delta.push(k2);
        }
    }

    decents k = delta.front();
    delta.pop();
    ll the_max = is_decent(k);
    while(!delta.empty()){
        k = delta.front();
        delta.pop();
        the_max = max(the_max, is_decent(k));
    }
    return the_max;
}

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << bt(n) << endl;
    }
    return 0;
}
