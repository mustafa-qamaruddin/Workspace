#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INPUT_SIZE = 1000000;
long long arr[INPUT_SIZE];

int random_pivot(int p, int r)
{
    return (p + rand() % (r-p+1));
}

int partition(int p, int r)
{
    int pivot = random_pivot(p, r);
    int x = arr[pivot];
    int i = p;
    int j = p;
    while(int j <= pivot)
    {
        if(arr[j] > )
    }
}

quick_sort(int p, int r)
{
    while( p < r)
    {
        q = partition(int p, int r);
        quick_sort(p, q-1);
        quick_sort(q+1, r);
    }
}

void read_array_from_file()
{
    fstream fs;
    fs.open("algo1-programming_prob-2sum.txt", fstream::in);
    string tmp;
    long long element;
    stringstream ss;
    int i = 0;
    while(getline(fs, tmp))
    {
        ss << tmp;
        ss >> arr[i];
        ss.clear();
        i++;
    }
    fs.close();
}

void fn_2_sum()
{
    for(long long t = -10000; t <= 10000; t++)
    {
        unordered_set<long long>::iterator itr = my_hash_table.begin();
        while(itr != my_hash_table.end())
        {
            cout << *itr << endl;
            ++itr;
        }
    }
}

int main()
{
    /*
        Insert elements of A into Hash Table H
        Foreach X in A, Look-up T-X in H
        Run Time Complexity : O(n)*
    */
    /*
        Sort A in O(NLOG(N)) time
        Foreach X in A, Look for T-X in A via Binary-Search in O(LOGN) time
    */
    srand(time(NULL));
    read_array_from_file();
    fn_2_sum();
    return 0;
}
