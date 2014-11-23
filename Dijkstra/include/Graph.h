#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <list>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef list<pii> lii;

typedef priority_queue<pii, vii, greater<pii> > pq;

struct vertex
{
    int label;
    lii adjacency_list; // pair(vertex_label, weight)
    long adjacency_size;
};

typedef vector<vertex> g;

const int OO = 1000000;

class Graph
{
    public:
        Graph();
        virtual ~Graph();
        Graph(const Graph& other);
        Graph& operator=(const Graph& other);

        void read_file(string);
        void display();
        void dijkstra(int, int);
        void dijkstra_loop();
    protected:
    private:
        g the_graph;
        long num_vertices;
        vi distances;
        vi explored;
};

#endif // GRAPH_H
