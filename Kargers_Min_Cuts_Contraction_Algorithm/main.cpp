/**
 * Question 1
 Download the text file here. (Right click and save link as)
 The file contains the adjacency list representation of a simple undirected graph. There are 200 vertices labeled 1 to 200. The first column in the file represents the vertex label, and the particular row (other entries except the first column) tells all the vertices that the vertex is adjacent to. So for example, the 6th row looks like : "6	155	56	52	120	......". This just means that the vertex with label 6 is adjacent to (i.e., shares an edge with) the vertices with labels 155,56,52,120,......,etc

 Your task is to code up and run the randomized contraction algorithm for the min cut problem and use it on the above graph to compute the min cut (i.e., the minimum-possible number of crossing edges). (HINT: Note that you'll have to figure out an implementation of edge contractions. Initially, you might want to do this naively, creating a new graph from the old every time there's an edge contraction. But you should also think about more efficient implementations.) (WARNING: As per the video lectures, please make sure to run the algorithm many times with different random seeds, and remember the smallest cut that you ever find.) Write your numeric answer in the space provided. So e.g., if your answer is 5, just type 5 in the space provided.
 */

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main() {
	for (int i = 0; i < 10000; i++) {
		srand(time(NULL));
		Graph G("Input.in");
		// G.display();
		cout << "Min Cuts: " << G.contract() << endl;
		// G.display();
	}
	return (0);
}
