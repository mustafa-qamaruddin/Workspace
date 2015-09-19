#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

ll chocolate_feast(ll n, ll c, ll m){
    ll number_of_chocos = n / c;
    ll remainder_wrappers = number_of_chocos % m;
    ll additional_chocos = number_of_chocos / m;
    ll extra_chocos = (remainder_wrappers + additional_chocos) / m;
    return (number_of_chocos + additional_chocos + extra_chocos);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    freopen("inputs.dat", "r", stdin);
    freopen("my_outputs.dat", "w", stdout);
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
