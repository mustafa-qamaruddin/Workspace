#include <iostream>

using namespace std;

typedef long long ull;

/*
 * nC4 * mC1 * (n+m-5)C(t-5)
 *
 * nCk = n! / k! / (n-k)! = n(n-1)(n-2)...(n-k+1) / k(k-1)(k-2)...1
 */

ull factorial(int x) {
	ull ret = 1;
	for (int i = 1; i <= x; i++) {
		ret *= i;
	}
	return ret;
}

ull nCkl(int n, int k) {
//	if (k > n)
//		return 0;
	ull ret = 1;
	for (int i = 0; i <= k + 1; i++) {
		ret *= (n - i);
	}
	cout << ret << endl;
	return (ret / factorial(k));
}

ull nCk(int n, int k) {
	//if (k > n)
	//return 0;

	return factorial(n) / factorial(k) / factorial(n - k);
}

int main() {
	int n, m, t;
	ull npr = 1;
	cin >> n >> m >> t;
	//if (t < n + m)
		//cout << 0 << endl;
	//else {
		// nC4
		npr *= nCk(n, 4);
		// mC1
		npr *= nCk(m, 1);
		// rem
		npr *= nCk(n + m - 5, t - 5);
		cout << npr << endl;
	//}
	return (0);
}
