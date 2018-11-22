
#include  <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
	//INSERTION SORT
	for (int j = 1; j < length; j++) {
		int m =0;
		int temp; // m is used to keep track of the cycles
		m = j;

		while(j>0 && B[j][m] < B[j][m-1]) 
		{
				//swap(a[m],a[m-1]);
				//m = m-1;
				
				temp = B[j][m];
				B[j][m] = B[j][m-1];
				B[j][m-1] = temp;
				
		}
	}
*/
void SelectionSort (vector<float>&a) {
	int min; 
	int temp;
	int i,j;
	for (i = 0; i < a.size(); i++)
	{
		min = i;
		for (j=i+1; j<a.size(); j++)
		{
			if (a[j] < a[min])
			{
				min=j;
			}
			swap(a[i],a[min]);
		//temp = a[i];
		//a[i] = a[min];
		//a[min]=temp;
		}
	}
}


void BucketSort(float a[], int size){
	int j;
	int length = size;
	vector< vector<float> >B(length);
	//stores the array elements in the proper buckets
	for (j=0; j<length; j++){

		float var_a = (a[j]*length); 	//typecasting 
		int var_b = (int)var_a;			//turns float into int values

		B[var_b].push_back(a[j]);		//inserts the float values in the buckets
		//InsertionSort(B[j], length);
	}

	
	for(int j=0; j<length; j++)
		SelectionSort(B[j]);

	//This loop prints the sorted elements from the bucket
	for(int i = 0; i < length; i++){
		for(int r = 0; r < B[i].size(); r++){
			cout << B[i][r] << endl;
		}

	}
	
}

int main(){
	int numValues;

	cin >> numValues;
	float a[numValues];

	for (int i=0; i<numValues; i++){
		cin >> a[i];
	}

	BucketSort(a, numValues);

	
	return 0; 


}