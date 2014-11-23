#include "Graph.h"

Graph::Graph()
{
    //ctor
    read_file("dijkstraData.txt");
    //read_file("tc_4.txt");

    distances.resize(num_vertices+1);
    explored.resize(num_vertices+1);
    fill(distances.begin(), distances.end(), OO);
    fill(explored.begin(), explored.end(), false);

    dijkstra_loop();
    display();
}

Graph::~Graph()
{
    //dtor
}

Graph::Graph(const Graph& other)
{
    //copy ctor
}

Graph& Graph::operator=(const Graph& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Graph::read_file(string f){
    fstream fs;
    fs.open(f.c_str(), fstream::in);
    int u, v, w;
    char c;
    string line;

    num_vertices = 0;
    while(getline(fs, line)) // O(N)
    {
        stringstream ss;
        ss << line;

        ss >> u;
        vertex o_vertex;
        o_vertex.label = u;
        o_vertex.adjacency_size = 0;
        while(ss >> v >> c >> w){
            o_vertex.adjacency_list.push_back(make_pair(v, w)); // O(1) :: doubly linked list
            o_vertex.adjacency_size++;
        }

        the_graph.push_back(o_vertex);
        num_vertices++;
    }
}

void Graph::display()
{
    cout << "GRAPH" << endl;
    for(long i = 1; i <= num_vertices; i++)
    {
        cout << "Label:" << setw(5) << the_graph[i-1].label << endl;
        lii::iterator itr = the_graph[i-1].adjacency_list.begin();
        while(itr != the_graph[i-1].adjacency_list.end())
        {
            cout << setw(5) << (*itr).first << "," << (*itr).second;
            ++itr;
        }
        cout << endl;
    }
    cout << endl;

    cout << "DISTANCES" << endl;
    for(long i = 1; i <= num_vertices; i++)
    {
        cout << "INDEX:" << setw(5) << i
        << setw(20) << "DISTANCE:" << setw(5) << distances[i]
        << endl;
    }
    cout << endl;

    cout << "COURSERA" << endl;
    cout << distances[7] << ","
    << distances[37] << ","
    << distances[59] << ","
    << distances[82] << ","
    << distances[99] << ","
    << distances[115] << ","
    << distances[133] << ","
    << distances[165] << ","
    << distances[188] << ","
    << distances[197] << endl;
}

void Graph::dijkstra_loop()
{
    for(long i = num_vertices; i > 0; i--) // O(N)
    {
        int label_i = the_graph[i-1].label;
        if(explored[label_i])
            continue;
        dijkstra(1, label_i);
    }
}

/**
1  function Dijkstra(Graph, source):
2      dist[source] := 0                     // Initializations
3      for each vertex v in Graph:
4          if v ≠ source
5              dist[v] := infinity           // Unknown distance from source to v
6              previous[v] := undefined      // Predecessor of v
7          end if
8          Q.add_with_priority(v,dist[v])
9      end for
10
11
12     while Q is not empty:                 // The main loop
13         u := Q.extract_min()              // Remove and return best vertex
14         mark u as scanned
15         for each neighbor v of u:
16             if v is not yet scanned:
17                 alt = dist[u] + length(u, v)
18                 if alt < dist[v]
19                     dist[v] := alt
20                     previous[v] := u
21                     Q.decrease_priority(v,alt)
22                 end if
23             end if
24         end for
25     end while
26     return previous[]
**/
void Graph::dijkstra(int src, int dest)
{
    cout << "***" << endl;
    cout << "FROM:" << setw(5) << src << endl;
    cout << "TO:" << setw(5) << dest << endl;
    pq o_pq;
    o_pq.push(make_pair(0, src));
    distances[src] = 0;
    while(!o_pq.empty())
    {
        pii k = o_pq.top();
        o_pq.pop();

        int k_label = k.second;
        int k_weight = k.first;

        cout << setw(20) << "POP:" << setw(5) << k_label << endl;

        explored[k_label] = true;

        lii::iterator itr = the_graph[k_label-1].adjacency_list.begin();
        while(itr != the_graph[k_label-1].adjacency_list.end())
        {
            int c_label = (*itr).first;
            int c_weight = k_weight + (*itr).second;

            cout << setw(30) << "CHILD:" << c_label << endl;

            if( explored[c_label]){
                ++itr;
                continue;
            }

            cout << "LABEL:" << setw(5) << c_label << " &WEIGHT:"<< setw(5) << c_weight << " &DST:" << setw(5) << distances[c_label] << endl;

            if( c_weight < distances[c_label])
            {
                distances[c_label] = c_weight;
                o_pq.push(make_pair(c_weight,c_label));
                cout << "PUSH:" << setw(5) << c_label << endl;
            }
            ++itr;
        }
    }
}
