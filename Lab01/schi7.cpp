#include <iostream>
using namespace std; 

int linearSearch (int num, int search, int array[]) {
 
int j = -1;

	for (int m = 0; m < num; m++) {
		if (array[m] == search) {
			return m;
		
		}
	}

	return j;
}
	

int main () {

int numInts; 
cin >> numInts;

int searchNum;
cin >> searchNum;

int arr[numInts];

int result;

	for (int i=0; i< numInts; i++){	

		cin >> arr[i]; 
	}
	
	// for (int i = 0; i < numInts; ++i) {
	// 	cout << arr[i] << " ";
	// }
	// std::cout << "\n";

	result = linearSearch (numInts, searchNum, arr);	

	cout << result << endl; 
}