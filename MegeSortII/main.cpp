/*
 * main.cpp
 *
 *  Created on: Oct 26, 2014
 *      Author: qamar-ud-din
 */
#include <iostream>
#include <fstream>

using namespace std;

const int OO = 1e9;
long long int num_invs = 0; // #Inversions

void merge(int A[], int P, int Q, int R) {
	int n1 = Q - P + 1;
	int n2 = R - Q;

	int* AL = new int[n1 + 1];
	int* AR = new int[n2 + 1];

	for (int i = 0; i < n1; i++)
		AL[i] = A[P + i];
	AL[n1] = OO;

	for (int i = 0; i < n2; i++)
		AR[i] = A[Q + i + 1];
	AR[n2] = OO;

	int i = 0;
	int j = 0;
	for (int k = P; k <= R && !(i == n1 && j == n2); k++) {
		if (AL[i] <= AR[j]) {
			A[k] = AL[i];
			i++;
		} else {
			A[k] = AR[j];
			j++;
			num_invs += n1 - i;
		}
	}
}

void mergeSort(int A[], int P, int R) {

	if (P >= R)
		return;

	int Q = (P + R) / 2;

	mergeSort(A, P, Q);
	mergeSort(A, Q + 1, R);

	merge(A, P, Q, R);
}

int main() {
	freopen("IntegerArray.txt", "r", stdin);

	int A[100001];

	int i = 0;
	while (cin >> A[i]) {
		i++;
	}

	mergeSort(A, 0, i - 1);

	for (int j = 0; j < i; j++)
		cout << A[j] << endl;

	cout << "#Inversions: " << num_invs << endl;

	return (0);
}
