#include <iostream>
#include <limits>
using namespace std; 

int FindMaxCrossing (int arr[], int low, int mid, int high) {
	int leftsum = std::numeric_limits<int>::min();
	
	int sum = 0;
	//int maxleft, maxright;

//adds the total of the left side of the array
	for (int j = mid; j>=low; j--) {
		sum = sum + arr[j];
		if (sum > leftsum){
			leftsum = sum;
		//	maxleft = j;
		}
	}
	int rightsum = std::numeric_limits<int>::min();
	sum = 0;

//adds the total of the right side of the array
	for (int k = mid+1; k <= high; k++) {
		sum = sum + arr[k];
		if (sum > rightsum) {
			rightsum = sum;
		//	maxright = k;
		}
	}
	return leftsum+rightsum;

}


int FindMaxSubarray (int arr[], int low, int high) {

	int mid, left_sum, right_sum, cross_sum;
	// left_low, left_high, right_low, right_high, cross_low, cross_high;

	if(high == low) {
		return (arr[low]);
	} 

	else {
		(mid = (low+high)/2); 
	}

	left_sum = FindMaxSubarray (arr, low, mid);
	right_sum = FindMaxSubarray (arr, mid+1, high);
	cross_sum = FindMaxCrossing (arr, low, mid, high);

	
	if (left_sum >= right_sum && left_sum >= cross_sum) {
		return left_sum;
	}
	else if (right_sum >= left_sum && right_sum >= cross_sum) {
		return right_sum;
	}
		else {
			return cross_sum;
	}

}

int main () {

	int arrSize; 
	cin >> arrSize;
	int lowNum = 0;
	int highNum = arrSize-1;
	//int mid = (low + high)/2;

	int array[arrSize];

	for (int i = 0; i< arrSize; i++) {
		cin >> array[i];
	}

	cout << FindMaxSubarray (array, lowNum, highNum); 

	return 0;

}
