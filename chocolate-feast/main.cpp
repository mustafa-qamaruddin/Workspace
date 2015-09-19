#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

ll chocolate_feast(ll n, ll c, ll m)
{
    ll n_of_chocos = n / c;
    ll ret = n_of_chocos;
    while(n_of_chocos / m > 0)
    {
        ret += n_of_chocos / m;
        n_of_chocos = n_of_chocos % m + n_of_chocos / m;
    }
    return ret;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    freopen("inputs.dat", "r", stdin);
//    freopen("my_outputs.dat", "w", stdout);
    ll t,n,c,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>c>>m;
        ll answer= chocolate_feast(n, c, m);
        cout<<answer<<endl;
    }
    return 0;
}
