/*
 * 443B.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: qamar-ud-din
 */

#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	int k;

	int max_2N = 0;

	getline(cin, s);
	cin >> k;

	//int index_lc = (int) s.size() - 1;
	for (int index_lc = (int) s.size() - 1; index_lc > 0; index_lc--) {
		char lc = s[index_lc];

		for (int i = 0; i < index_lc; i++) {
			if (s[i] == lc) {
				int ss_len = index_lc - i - 1;
				if (ss_len > k)
					ss_len = k;
				string ss = s.substr(i + 1, ss_len);
				string new_s = s.append(ss);

				//int index_lc_2 = (int) new_s.size() - 1;
				for (int index_lc_2 = (int) new_s.size() - 1; index_lc_2 > 0;
						index_lc_2--) {
					char lc_2 = new_s[index_lc_2];

					for (int j = 0; j < index_lc_2; j++) {
						if (new_s[j] == lc_2) {
							int two_N = 2;

							int l = index_lc_2 - 1, m = j - 1;
							while (l > j && l > 0 && m >= 0) {
								if (new_s[l] != new_s[m])
									break;
								two_N += 2;
								l--;
								m--;
							}
							if (two_N > max_2N)
								max_2N = two_N;
						}
					}
				}
			}
		}

	}
	cout << max_2N;

	return (0);
}

