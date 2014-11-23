#include <iostream>
#include <fstream>

using namespace std;

const int CAP_Arr = 100001; // maximum capacity
int lenArr = 0; // actual length
int arr[CAP_Arr]; // array
int numInv = 0; // #inversions

void cpRem(int* subArr, int subIndex, int arrIndex, int subSize) {
	for (int i = subIndex; i < subSize; i++) {
		arr[arrIndex] = subArr[i];
	}
}

void merge(int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	int* arrL = new int[n1];
	int* arrR = new int[n2];

	for (int i = 0; i < n1; i++)
		arrL[i] = arr[p + i];

	for (int i = 0; i < n2; i++)
		arrR[i] = arr[q + 1 + i];

	int i = 0; // arrL indexer
	int j = 0; // arrR indexer
	for (int k = p; k <= r; k++) {
		if (i >= n1) {
			cpRem(arrR, j, k, n2);
			break;
		}

		if (j >= n2) {
			cpRem(arrL, i, k, n1);
			break;
		}

		if (arrL[i] <= arrR[j]) {
			arr[k] = arrL[i];
			i++;
		} else {
			arr[k] = arrR[j];
			j++;
			numInv++;
		}
	}
}

void mergeSort(int start, int end) {
	cout << "start: " << start << " && end: " << end << endl;
	// base case
	if (start >= end) {
		return;
	}

	int median = (start + end) / 2; //??
	cout << "median: " << median << endl;

	mergeSort(start, median);
	mergeSort(median + 1, end);

	merge(start, median, end);
}

int main() {
	freopen("IntegerArray.txt", "r", stdin);
	while (cin >> arr[lenArr]) {
		lenArr++;
	}

	mergeSort(0, lenArr - 1);

	for (int i = 0; i < lenArr; i++)
		cout << arr[i] << endl;

	cout << "#Inversions: " << numInv << endl;

	return (0);
}
