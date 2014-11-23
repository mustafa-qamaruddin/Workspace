#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <unistd.h>

using namespace std;

struct edge {
	int u, v;
};

typedef set<int> lvp;
typedef map<int, lvp> milvp;
typedef vector<edge> ve;

class Graph {
public:
	Graph(string inputFile) {
		N = 0;
		M = 0;
		fstream fs;
		fs.open(inputFile.c_str(), fstream::in);
		string line;
		while (fs.is_open() && getline(fs, line)) {
			stringstream ss;
			ss << line;
			int vLabel;
			ss >> vLabel;
			lvp adjList;
			int neighbor;
			while (ss >> neighbor) {
				pair<lvp::iterator, bool> pair_set = adjList.insert(neighbor);

				if (!pair_set.second)
					cout << "Parallel Edge Canceled at E(U:" << vLabel
							<< " , V:" << neighbor << ")" << endl;
				// edge handling
				edge ein;
				ein.u = vLabel;
				ein.v = neighbor;
				E.push_back(ein);
				M++;
			}
			pair<milvp::iterator, bool> ret;
			ret = V.insert(make_pair(vLabel, adjList));
			if (ret.second) {
				N++;
			}
			nextLabel = vLabel + 1;
		}
		removed = new bool[N];
		memset(removed, false, sizeof(removed));
		fs.close();
	}
	void display() {
		milvp::iterator itr = V.begin();
		while (itr != V.end()) {
			cout << "Label: " << (*itr).first << endl;
			lvp::iterator itr2 = (*itr).second.begin();
			while (itr2 != (*itr).second.end()) {
				cout << setw(6) << *itr2;
				++itr2;
			}
			cout << endl;
			++itr;
		}
	}
	int randomEdge() {
		usleep(10 * 1000);
		srand(time(NULL) * N + M);
		for (int i = 0; i < 100; i++)
			rand();
		return (rand() % M);
	}
	int randomVertex() {
		usleep(1000);
		srand(time(NULL) * N + M);
		return rand() % N;
	}
	int randomNeighbor(milvp::iterator itr) {
		usleep(1000);
		srand(time(NULL) * N + M);
		int max = (int) (*itr).second.size();
		return rand() % max;
	}
	/**
	 procedure contract(G=(V,E)):
	 while |V| > 2
	 choose e\in E uniformly at random
	 G <- G/e
	 return the only cut in G
	 */

	long int contract() {
		while (N > 2) {
			int edge = randomEdge();

			// combine two vertices in one new vertex
			// remove self reference loops / edges
			// point all in / out edges to the new combined vertex
			// update vertices adjacency lists

			int u = randomVertex(); // E[edge].u;
			if (removed[u])
				continue;
			// int v = E[edge].v;

			milvp::iterator itr_u = V.find(u);
			if (itr_u == V.end())
				continue;

			int v = randomNeighbor(itr_u);
			if (removed[v])
				continue;

//			cout << "Random E:" << edge << " (U: " << u << " , " << "V: " << v
//					<< ")" << endl;

			lvp &adjacency_list = (*itr_u).second;
			int UM = (int) adjacency_list.size();

			milvp::iterator itr_v = V.find(v);
			if (itr_v == V.end())
				continue;
			lvp::iterator itr_adj = (*itr_v).second.begin();

			int VM = (int) (*itr_v).second.size();
			while (itr_adj != (*itr_v).second.end()) {
				//cout << *itr_adj << endl;
				if (*itr_adj != v && *itr_adj != u) {
					adjacency_list.insert(*itr_adj);
				}
				++itr_adj;
			}

			lvp::iterator itr_adj_list = adjacency_list.begin();
			//cout << endl << "adjacency list:" << endl;
			while (itr_adj_list != adjacency_list.end()) {
				//cout << setw(7) << *itr_adj_list;
				++itr_adj_list;
			}
			cout << endl;

			// remove self loop
			lvp::iterator itr_self_lp = adjacency_list.find(u);
			if (itr_self_lp != adjacency_list.end()) {
				//cout << "Remove Self LOoP: " << u << *itr_self_lp << endl;
				adjacency_list.erase(itr_self_lp);
			}

			M = M - ((UM + VM) - (int) adjacency_list.size());
//			cout << "|E| = " << M << endl;
			shrink(u, v);

			// erase the (u,v)
			V.erase(itr_v);
			removed[v] = true;
			N--;

			// update edges vector
			// remove edge to shrink
//			cout << "Erase Edge " << edge << endl;
			E.erase(E.begin() + edge);

//			cout << endl << "Edge Was Deleted" << endl;
			cout << "|V| = " << N << endl;
			int x;
//			cin >> x;
//			cout << "N: " << N << " M:" << M << endl << endl;
			// display();
		}

		return count();
	}

	int count() {
		int count = 0;
		milvp::iterator itr = V.begin();
		while (itr != V.end()) {
			cout << "Label: " << (*itr).first << endl;
			lvp::iterator itr2 = (*itr).second.begin();
			while (itr2 != (*itr).second.end()) {
				count++;
				cout << setw(6) << *itr2;
				++itr2;
			}
			cout << endl;
			++itr;
		}
		return count;
	}

	// ????
	// loop all vertices adjacency lists to find the removed two vertices ? note index has changed and error will arise here???????
	// all points to v will point to u now
	void shrink(int u, int v) {
		milvp::iterator itr = V.begin();
		while (itr != V.end()) {
			//cout << "inspecting: " << (*itr).first << " XXXXX" << endl;
			//cout << "Switch Loops to U " << u << " V " << v;
			lvp adj = (*itr).second;

			adj.erase(v);
			/// when switching edge from v to u , there was already another u, then #edges M is reduced by one
			pair<lvp::iterator, bool> pair_set = adj.insert(u);
			if (!pair_set.second) {
				M--;
			}

			++itr;
		}
	}
private:
	milvp V; // V:Vertices
	ve E; // E: Edges
	long int N; // N: |V|
	long int M; // M: |E|
	int nextLabel;
	bool *removed;
protected:
};
#endif
