#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

struct node {
	int row, col;
	node() {
	}
	node(int r, int c) :
			row(r), col(c) {
	}
	bool operator==(const node & rhs) {
		if (rhs.row == row && rhs.col == col)
			return true;
		else
			return false;
	}
};

int n;
bool** vis;
node** table;

queue<node> q;
int minMoves = 1e8;

int directions[4][4] = { { -1, -1 }, { -1, +1 }, { +1, -1 }, { +1, +1 } };

int cntPath(node src, node dest) {
	int cnt = 1;
	node current = table[dest.row][dest.col];
	while (!(current == src)) {
		// increment only if bishop will turn
		node next = table[current.row][current.col];
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			if (next.row == current.row + directions[i][0]
					&& next.col == current.col + directions[i][1]) {
				flag = true;
				break;
			}
		}
		if (!flag)
			cnt++;
		current = next;
	}
	return cnt;
}

int bfs(node src, node dest) {

	// push to queue
	q.push(src);
	vis[src.row][src.col] = true;

	// if queue not empty
	while (!q.empty()) {
		// pop last one from stack
		node k = q.front();
		q.pop();

		// if is target return
		if (k == dest) {
			return cntPath(src, dest);
		}

		// push children to queue
		for (int i = 0; i < 4; i++) {
			int newR = k.row + directions[i][0];
			int newC = k.col + directions[i][1];

			node child(newR, newC);

			// not valid node
			if (newR <= 0 || newR > n || newC <= 0 || newC > n)
				continue;

			// not visited
			if (!vis[newR][newC]) {
				vis[newR][newC] = true;
				table[newR][newC] = k;
				q.push(child);
			}
		}
	}
	return -1;
}

int main() {
	int tc, t, r1, c1, r2, c2;
	string bl; // blank line
	cin >> tc;
	getline(cin, bl);
	while (tc--) {
		cin >> t >> n;
		while (t--) {
			cin >> r1 >> c1 >> r2 >> c2;
			if (((r1 + c1) % 2) != ((r2 + c2) % 2)) {
				cout << "no move" << endl;
			} else {
				if (r2 == r1 && c2 == c1)
					cout << 0 << endl;
				else if (abs(r2 - r1) == abs(c2 - c1))
					cout << 1 << endl;
				else
					cout << 2 << endl;
				/**
				 // reset
				 minMoves = 0;
				 vis = new bool*[n + 1];
				 table = new node*[n + 1];
				 for (int i = 0; i <= n; i++) {
				 vis[i] = new bool[n + 1];
				 table[i] = new node[n + 1];
				 }
				 memset(vis, false, sizeof(vis));
				 memset(table, NULL, sizeof(table));
				 // bfs
				 cout << bfs(node(r1, c1), node(r2, c2)) << endl;
				 **/
			}
		}
		getline(cin, bl);
	}
	return (0);
}
