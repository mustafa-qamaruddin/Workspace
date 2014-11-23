/*
 * main.cpp
 *
 *  Created on: Oct 30, 2014
 *      Author: Qamar-ud-din
 */
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int MAXCAP = 100000;

class QuickSort {
public:
	QuickSort() {
		this->num_comp = 0;
		arr = new int[MAXCAP];
		read();
		sort(0, CURSIZE - 2);
		print();
	}
	void read() {
		CURSIZE = 0;
		while (cin >> arr[CURSIZE++] && CURSIZE < MAXCAP)
			;
	}
	void swap(int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	int partition(int p, int r) {
		this->num_comp += abs(p - r);
		int x = arr[p]; // using first element as pivot
		int i = p + 1;
		for (int j = p + 1; j <= r; j++) {
			if (arr[j] < x) {
				swap(i, j);
				i++;
			}
		}
		swap(i - 1, p);
		return i - 1; // return pivot
	}
	void sort(int p, int r) {
		if (p >= r)
			return;
		//swap(p, r); // exchange last element with first element # last element is pivot
		swap(p, medianOfThree(p, r)); // exchange median element with first element # median element is pivot
		int q = partition(p, r); // put q in correct place
		sort(p, q - 1); // sort sub array before q
		sort(q + 1, r); // sort sub array after q
	}
	void print() {
		for (int i = 0; i < CURSIZE - 1; i++) {
			cout << arr[i] << endl;
		}
		cout << "# Comparsions: " << this->num_comp << endl;
	}
	//"median-of-three" pivot rule.
	/**
	 choose the pivot as follows
	 1 -  Consider the first, middle, and final elements of the given array.
	 2 - If the array has odd length it should be clear what the "middle" element is;
	 3 - with even length 2k, use the kth element as the "middle" element. So for the array 4 5 6 7, the "middle" element is the second one ---- 5 and not 6!
	 4 -  Identify which of these three elements is the median; value is in between the other two)
	 5 - use this as your pivot
	 */
	int medianOfThree(int p, int r) {
		int m = (p + r) / 2; // median
		// set: {first: arr[p], median: arr[m], last: arr[r]}
		// last < first < median OR last > first > median
		if ((arr[p] < arr[m] && arr[p] > arr[r])
				|| (arr[p] > arr[m] && arr[p] < arr[r])) {
			return p;
		}
		// first < last < median OR first > last > median
		if ((arr[r] < arr[m] && arr[r] > arr[p])
				|| (arr[r] > arr[m] && arr[r] < arr[p])) {
			return r;
		}
		// last < median < first OR last > median > first
		if ((arr[m] < arr[p] && arr[m] > arr[r])
				|| (arr[m] > arr[p] && arr[m] < arr[r])) {
			return m;
		}
		return 0;
	}
private:
	int CURSIZE;
	int* arr;
	long long int num_comp;
};

int main() {
	freopen("IntegerArray.txt", "r", stdin);
	QuickSort();
	return (0);
}
