#include <iostream>
#include <cstring>

using namespace std;

typedef long long int ll;

const int SZARR = 5;
int ARR[SZARR] = { 50, 25, 10, 5, 1 };

const int MAXAMOUNT = 7489;
int mem[SZARR + 1][MAXAMOUNT + 1];

ll dp(int index, int sum, int goal) {

	if (sum > goal)
		return 0;
	if (sum == goal)
		return 1;
	if (index >= SZARR)
		return 0;

	int& ret = mem[index][sum];
	if (ret != -1) {
		return ret;
	}

	ll nWays = dp(index + 1, sum, goal); // leave it
	int i = 1;
	while (sum + i * ARR[index] <= goal) {
		nWays += dp((index + 1), (sum + i * ARR[index]), goal); // take it i times
		i = i + 1;
	}
	return ret = nWays;
}

int main() {
	int amount;
	while (cin >> amount) {
		memset(mem, -1, sizeof(mem));
		if (amount == 0)
			cout << 1 << endl;
		else
			cout << dp(0, 0, amount) << endl;
	}
	return (0);
}
