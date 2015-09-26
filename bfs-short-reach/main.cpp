#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <list>

using namespace std;

#define Edge_Cost 6

enum COLORS {WHITE, GREY, BLACK};

struct node
{
    COLORS color = WHITE;
    bool visited = false;
    vector<int> adjl;
    int parent;
    int distance = -1;
};

void display_graph(node* a_graph, int sz)
{
    for(int i = 0; i <= sz; i++)
    {
        cout << i << ":";
        vector<int>::iterator itr = a_graph[i].adjl.begin();
        while(itr != a_graph[i].adjl.end())
        {
            cout << *itr << ", ";
            ++itr;
        }
        cout << endl;
    }
}


void print_distances(node* a_graph, int sz, int s)
{
    for(int i = 1; i <= sz; i++)
    {
        if(i != s)
            cout << a_graph[i].distance << " ";
    }
    cout << endl;
}

void calculate_distance(node* a_graph, int an_index){
    int d = 0;
    int i = an_index;
    while(a_graph[i].parent != NULL){

        d += Edge_Cost;
        i = a_graph[i].parent;

    }
    a_graph[an_index].distance = d;
}

void bfs(node* a_graph, int sz, int s)
{
    queue<int> q;
    a_graph[s].parent = NULL;
    a_graph[s].color = GREY;
    a_graph[s].visited = true;
    a_graph[s].distance = 0;
    q.push(s);
    int distance = 0;
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        vector<int>::iterator itr = a_graph[k].adjl.begin();
        vector<int>::iterator itr_end = a_graph[k].adjl.end();
        while(itr != itr_end)
        {
            if(a_graph[*itr].visited)
            {
                ++itr;
                continue;
            }
            a_graph[*itr].visited = true;
            a_graph[*itr].color = GREY;
            a_graph[*itr].parent = k;
            a_graph[*itr].distance = a_graph[k].distance + Edge_Cost;
            q.push(*itr);
            ++itr;
        }
    }
    print_distances(a_graph, sz, s);
}

int main()
{
//    freopen("input01.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, m, x, y, s;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        node* my_graph = new node[n+1];
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;
            my_graph[x].adjl.push_back(y);
            my_graph[y].adjl.push_back(x);
        }
        cin >> s;
//        display_graph(my_graph, n);
        bfs(my_graph, n, s);
    }
    return 0;
}
