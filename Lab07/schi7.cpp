
#include <iostream>
using namespace std; 

//stable sort: countingsort, mergesort, etc 
void CountingSort(int a[], int l, int arrsize) {
	//std::vector<int> c;
	int k = arrsize - 1;
	int c[arrsize];
	int i, j;
	for (i=0; i < k; i++) {
		c[i] = 0;
	}
	for (j=1; j <= arrsize; j++){
		c[a[j]] = c[a[j]]+1;
	}
	for(i=1; i<=k; i++){
		c[i] = c[i] + c[i-1];
	}
	for(j = arrsize; j >= 1; j--){
		c[a[j]] = a[j];
		c[a[j]] = c[a[j]] - 1;
	}
}

void radixSort(int a[], int arrsize){
	//int std::vector<int> b;
	int b[arrsize];
	for (int j=0; j < arrsize; j++){
		CountingSort(a, j, arrsize);
	}

}

int main() {
	int value;
	int arrsize = 10;
	int a[arrsize];
	//vectors are dynamic arrays but the array size is given so ill just arrays 
	//std::vector<int> a;

	for (int i = 0; i<arrsize; i++){
		cin >> a[value]; 
		//v.push_back(value);
	}

	radixSort(a, value);

	for (int j=0; j<arrsize; j++) {
		cout<<a[j]<< endl; 
	}

return 0;

}