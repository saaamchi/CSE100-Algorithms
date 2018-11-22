#include <iostream>
using namespace std; 

void insertionSort (int size, int arr[]) {

	//var that is used in the array	
	int m; 

	// temporary variable that is used to reassign the smaller number 
	int temp = 0; 

	for (int j = 1; j < size; j++) {

		// m is used to keep track of the cycles
		m = j;

		while ( m > 0 && arr[m] > arr[m-1]) {
				temp = arr[m];
				arr[m] = arr[m-1];
				arr[m-1] = temp;
				m = m-1;
			
		}

}	
	for(int i = 0; i < size; i++){
		cout << arr[i]<< ";";

	}

}

int main(){

	int num;
	cin>> num;
	int array[num];

	for( int i = 0; i < num; i++) {
	//	cin>> num;
		cin >> array[i];
	}

//calls sorting algorithm
	insertionSort(num, array);

	
return 0;
}