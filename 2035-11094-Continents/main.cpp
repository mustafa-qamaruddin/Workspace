/*
 * main.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: qamar-ud-din
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int MAXM = 20;
const int MAXN = 20;
char grid[MAXM][MAXN];
int vis[MAXM][MAXN];

const int NUMDIRS = 4;
//int directions[NUMDIRS][2] = { //
//		{ -1, -1 }, { -1, 0 }, { -1, 1 }, //
//				{ 0, -1 }, { 0, 1 }, //
//				{ 1, -1 }, { 1, 0 }, { 1, 1 } //
//		};

int directions[NUMDIRS][2] = { //
		{ -1, 0 }, //
				{ 0, -1 }, { 0, 1 }, //
				{ 1, 0 } //
		};

bool global_flag;

int x, y; // current continent position

int relax(int row, int col, int rows, int cols) {
	if (row == x && col == y) {
		global_flag = true;
		return 0;
	}

	int ret = 1;
	vis[row][col] = true;

	// loop 8 directions
	for (int i = 0; i < NUMDIRS; i++) {
		int newR = row + directions[i][0];
		int newC = col + directions[i][1];

		// fold-able j=0 and j=n-1 are tangent
		if (newC == -1)
			newC = cols - 1;
		else if (newC == cols)
			newC = 0;

		if (!vis[newR][newC] && grid[newR][newC] == grid[x][y] && newR >= 0
				&& newR < rows) {
			ret += relax(newR, newC, rows, cols);
		}
	}

	return ret;
}

int main() {
	int m, n, max, cont_sz, lands_sz;
	while (cin >> m && cin >> n && m <= 20 && n <= 20) {
		// reset
		memset(vis, 0, sizeof(vis));
		memset(grid, 0, sizeof(grid));
		max = 0;
		global_flag = false;
//		vpii lands;
//		lands_sz = 0;

		// input
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
//				if (grid[i][j] == 'l') {
//					lands.push_back(make_pair(i, j));
//					lands_sz++;
//				}
			}
		}

		// current content
		cin >> x >> y;
//		string tmp;
//		cin >> tmp;

		// loop lands
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
//				int row = lands[i].first;
//				int col = lands[i].second;
				if (!vis[i][j] && grid[i][j] == grid[x][y]) {
					cont_sz = relax(i, j, m, n);
					if (!global_flag && max < cont_sz) {
						max = cont_sz;
					}
					global_flag = false;
				}
			}
		}

		cout << max << endl;
	}
	return (0);
}

