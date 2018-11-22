#include <iostream>
using namespace std; 


void Merge(int ar[], int p, int q, int r) {

	int sizeL = q-p+1;
	int sizeR = r-q;

	int L[sizeL];
	int R[sizeR];

	int j,k,n;

//splitting inital array into two temp arrays
	for (j = 1; j < sizeL; j++) {
		L[j] = ar[p+j-1];
	}

	for (k = 0; k < sizeR; k++) {
		R[k] = ar[q+k];
	}

	j = 0;
	k = 0;
	n = 1;

	//while-loop keeps track of increments of Right and Left arrays
	while (j < sizeL && k < sizeR) {

		//assigns sorted values into final array
		if (L[j] <= R[k]) {
			ar[n] = L[j];
			j++;
		}

		else {
			ar[n] = R[k];
			k++;
		}
		n++;
	}

	while (j < sizeL) {
		ar[n] = L[j];
		j++;
		n++;
	}

	while (k < sizeR) {
		ar[n] = R[j];
		k++;
		n++;
	}

	for (int m = 0; m < r; m++) {
		cout<< ar[m] << ";" ;
	}
}

void Sort (int arr[], int first, int last) {
	int mid;

	if (first < last) {
		mid = (first+last)/2;

		Sort(arr, 1, mid);
		Sort(arr, mid+1, last);
	
		Merge(arr, first, mid, last);
	}
}


int main( ) {
	int numValues;
	cin >> numValues;
	
	int array [numValues];
	//int middle = (numValues)/2;

	for (int i = 0; i < numValues; i++) {
		cin >> array[i];
	}

	Sort (array, 0, numValues-1);
	
	return 0;
}
