/*
 * main.cpp
 *
 *  Created on: Oct 26, 2014
 *      Author: qamar-ud-din
 */
#include <iostream>
#include <cstring>

using namespace std;

const int MAXROWS = 100;
const int MAXCOLS = 100;
const int MAXDIRS = 8;

char SKY[MAXROWS][MAXCOLS];
int VIS[MAXROWS][MAXCOLS];
const int DIRECTIONS[MAXDIRS][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 },
		{ 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

bool validCell(int r, int c, int numRows, int numCols) {
	if (r >= 0 && r < numRows && c >= 0 && c < numCols)
		return true;
	else
		return false;
}

void blockAdj(int r, int c, int numRows, int numCols) {
	bool flag = false;
	if (VIS[r][c] == -1)
		return;
	for (int i = 0; i < MAXDIRS; i++) {
		int newR = r + DIRECTIONS[i][0];
		int newC = c + DIRECTIONS[i][1];
		if (!validCell(newR, newC, numRows, numCols))
			continue;
		if (VIS[r][c] == -1) {
			flag = true;
			continue;
		}
		if (SKY[newR][newC] == '*') {
			flag = true;
//			VIS[newR][newC] = -1; // unnecessary
//			blockAdj(newR, newC, numRows, numCols);

		}
	}
	if (flag)
		VIS[r][c] = -1;
}

int main() {
	int r, c; // 0 < r,c < 101
	cin >> r >> c;
	while (!(r == 0 && c == 0)) {
		int cntStars = 0;
		memset(VIS, 0, sizeof(VIS));

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> SKY[i][j];
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (SKY[i][j] != '*')
					continue;
//				if (VIS[i][j] == -1)
//					continue;
				for (int k = 0; k < MAXDIRS; k++) {
					int newR = i + DIRECTIONS[k][0];
					int newC = j + DIRECTIONS[k][1];
					if (!validCell(newR, newC, r, c))
						continue;
//					blockAdj(newR, newC, r, c);
					if (SKY[newR][newC] == '*') {
						VIS[i][j] = -1;
						break;
					}
				}
				if (VIS[i][j] != -1)
					cntStars++;
			}
		}
		cout << cntStars << endl;
		cin >> r >> c;
	}
	return (0);
}

