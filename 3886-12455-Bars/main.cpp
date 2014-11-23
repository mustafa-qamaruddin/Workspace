#include <iostream>

using namespace std;

bool bt(int index, int sofar, int goal, int arrlen, int* arr) {
	// more
	if (sofar > goal)
		return false;
	// goal
	if (sofar == goal)
		return true;
	// array end
	if (index > arrlen)
		return false;
	// i:[0,1] possibilities [take, leave]
	for (int i = 0; i < 2; i++) {
		// mark

		// process
		if (bt(index + 1, sofar + arr[index], goal, arrlen, arr)
				|| bt(index + 1, sofar, goal, arrlen, arr))
			return true;
		// unmark
	}
	return false;
}

int main() {
	int tc, // 0 <= t <= 50 #test cases
			n, // 0 <= n <= 1000 ;desired length
			p; // 1 <= p <= 20 #bars
	int* bars; // array[0 -> p - 1] ;bars lengths
	cin >> tc;
	for (int t = 1; t <= tc && t >= 0 && t <= 50; t++) {
		cin >> n >> p;
		if (n < 0 || n > 1000 || p < 1 || p > 20)
			continue;
		bars = new int[p];
		for (int i = 0; i < p; i++) {
			cin >> bars[i];
		}

		if (n == 0)
			cout << "YES" << endl;
		else
			cout << ((bt(0, 0, n, p, bars)) ? "YES" : "NO") << endl;
	}
	return (0);
}
