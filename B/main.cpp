#include <iostream>

using namespace std;

#define MAX_WARRIORS 4001
#define MAX_LINKS 4001

struct warrior {
    int recognition = 0;
    int num_of_links = 0;
    int links[MAX_LINKS];
};
/**
*   ignore index 0
*/
int main(){
    int n, m;
    cin >> n >> m;
    warrior* arr_warriors = new warrior[n+1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        arr_warriors[a].links[arr_warriors[a].num_of_links] = b;
        arr_warriors[a].num_of_links++;
        arr_warriors[a].recognition++;

        arr_warriors[b].recognition++;
    }

    for(int i = 1; i <= n; i++){
        if(arr_warriors[i].num_of_links < 2)
            continue;
        for(int j = 0; j < arr_warriors[i].num_of_links; j++){

        }
    }
    return 0;
}
