#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	//freopen("input.in", "r", stdin);
	int l;
	cin >> l;
	while (l != 0) {
		int minR = 1e9, cnt = 0;
		char c, prev = 'a';
		string s;
		cin >> s;
		for (int i = 0; i < l; i++) {
			c = s[i];

			// no prev yet
			if ( (i == 0 || prev == 'a') && c != 'Z') {
				prev = c;
				cnt = 0;
				continue;
			}

			bool flag = false; // shorcut z
			switch (c) {
			case '.':
				cnt++;
				continue;
			case 'Z':
				minR = 0;
				flag = true;
				break;
			case 'R':
				if (prev == c) {
					cnt = 0;
				} else if (prev == 'D' || prev == 'Z') {
					cnt++;
					minR = min(minR, cnt);
					cnt = 0;
				} else {
					cnt = 0; // first char
				}
				prev = 'R';
				continue;
			case 'D':
				if (prev == c) {
					cnt = 0;
				} else if (prev == 'R' || prev == 'Z') {
					cnt++;
					minR = min(minR, cnt);
					cnt = 0;
				} else {
					cnt = 0; // first char
				}
				prev = 'D';
				continue;
			default:
				break;
			}
			if(flag)
				break;
		}
		cout << minR << endl;
		cin >> l;
	}
	return (0);
}
