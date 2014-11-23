#include "Graph.h"

int main()
{
    time_t start = time(NULL);
    Graph g;
    time_t span = time(NULL) - start;
    cout << fixed << setprecision(2);
    cout << "TOTAL TIME :=" << setw(5) << span << endl;
    return(0);
}
