#include <iostream>
using namespace std; 

//Root A[1]
//Parent(i) = [i/2]
//Left[i] = 2i
//Right[i] = 2i+1

// i is the root

void Max_Heapify (int array[], int i, int arrsize){
	int temp;

	//left child of node
	int left = (2*i);
	//right child of node
	int right = (2*i) + 1;
	

//if left child is bigger than parent, switch
	if ((left <= arrsize) && (array[left] > array[i])){
		largest = left; 
	} else {
		largest = i;
	}

//if the right child is bigger than the node, switch
	if ((right <= arrsize) && (array[right] > array[largest])) {
		largest = right;
	}

//if the parent isnt the biggest number, switch 
	if (largest != i) {
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp; 
		Max_Heapify(array, largest, arrsize); 
	}
}

//
void Build_Max_Heap (int array[], int arrsize) {
	for (int j = (arrsize/2); j >= 1; j-- ) {
		Max_Heapify(array, j, arrsize);
	}
}


void HeapSort (int array[], int arrsize) {
	Build_Max_Heap(array, arrsize);
	int temp;

//extracts the nodes and gives it back to Heapify to check again
	for(int i = arrsize; i >= 2; i-- ) {
		temp = array [1];
		array[1] = array[i];
		array[i] = temp;
		Max_Heapify (array, 1, i-1);
	}
}

int main () {
	int arrsize;
	cin >> arrsize;

	int array[arrsize];
	
	//root is 1 and not 0
	for (int i=1; i<= arrsize; i++) {
		cin >> array[i];
	}

	HeapSort(array, arrsize);

	for (int k = 1; k <= arrsize; k++) {
		cout << array[k] <<";";
	}
	return 0;
}