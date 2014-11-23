#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

typedef long long unsigned int ull;

int main() {
	int tc;
	//freopen("input.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		ull n, r;
		cin >> n;
		r = (-1 + sqrt(1 + 8 * n)) / 2;
		cout << r << endl;
	}
}
