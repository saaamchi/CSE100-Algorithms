//Randomized QuickSort 

#include <iostream>
#include <cstdlib>
using namespace std;


//Partition function found on pg 192 of book
int Partition(int array[], int p, int r){
	int x = array[r];
	int n = p-1;
	int temp;
	for(int m = p; m <= (r-1); m++ ) {
		if (array[m] <= x){
			n++;
			temp = array[n];
			array[n] = array[m];
			array[m] = temp;
		}
	}
	temp = array[n+1];
	array[n+1] = array[r];
	array[r] = temp;

	return (n+1);
}

 // the random number used is the random pivot 
// where it is checked

int Randomized_Partition(int array[], int p, int r){
	//int randomized = rand();
	int k = p + rand() % (r-p+1);
	int temp;
	temp = array[k];
	array[k] = array[r];
	array[r] = temp;

	return Partition(array, p, r);

}

void Randomized_Quicksort (int array[], int p, int r) {
	//int q = (p+r)/2;
	int q;

	if(p < r) {
		q = Randomized_Partition(array, p, r);
		Randomized_Quicksort(array, p, q-1);
		Randomized_Quicksort(array,q+1, r);
	}
}

int main () {
	int arrNum;
	cin >> arrNum;

	int p = 0; 
	int r = arrNum-1;
	int array[arrNum];

	for(int i=0; i < arrNum; i++){
		cin>>array[i];
	}

	Randomized_Quicksort (array, p, r);

	for (int j=0; j<arrNum; j++) {
		cout<<array[j]<<";"; 
	}

	return 0;
}