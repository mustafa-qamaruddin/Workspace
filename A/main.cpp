#include<iostream>
#include<queue>

using namespace std;

#define NUM_CANDIDATES 100

int main(){
    int n, limak, bribe = 0;
    priority_queue<int> pq;
    int votes[NUM_CANDIDATES];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> votes[i];
        if(i != 0)
            pq.push(votes[i]);
    }
    limak = votes[0];
    int x = pq.top();
    while(limak <= x){ // O(1)
        pq.pop(); // O(logN)
        x--;
        pq.push(x); // O(logN)
        limak += 1;
        bribe += 1;
        x = pq.top();
    }
    cout << bribe << endl;
    return 0;
}
