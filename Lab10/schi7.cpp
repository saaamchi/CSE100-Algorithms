#include <iostream>
#include "limits.h"
using namespace std; 

int h_twoFunct(int key){
	int h_two = (1 + (key % 11));
	return h_two;
}

int h_oneFunc(int key){
	int h_one = key % 13;
	
	//int h_value = (h_one + (size*h_two)) % 13;

	return h_one;
}

void Print(int hashTable[]){
	for (int i = 0; i < 13; i++)
	{
		if (hashTable[i] != INT_MIN){
			cout << hashTable[i] << endl;
		}
		else {
			cout << endl;
		}
	}
}

int Insert(int hashTable[], int key){
	int hsize = 13;
	int i = 0;
	while(i < hsize){
		int val = (h_oneFunc(key) + (i * h_twoFunct(key)));
		
		if (hashTable[val] == INT_MIN){		// only add element if it is empty
			hashTable[val] = key;
			return val;
		}
		//loop through the hashtable to find an "empty" spot 
		else {
			i++;
			//probably wrong 
			//for (int j = index; j < hsize; ++j){
			//	if (hashTable[j] == INT_MIN){
			//		hashTable[j] = key;
		}

	}
    return INT_MIN;
}
	
int Search(int hashTable[], int key){
	int i = 0;
	int hsize = 13;
	int val = h_oneFunc(key); // Check the ideal position of the key in the hash table
	
	while(i < hsize){
		if (hashTable[val] == key){
			return val;
        }

        if (val == h_oneFunc(key) && i != 0) { // If the search went back to the initial slot where it first searched, break the loop.
			break;
		}
        
        if (val == 13) { // When the search gets to the last element go back to first element
            val = 0;
        }
		val++;
		i++;
	}
	return INT_MIN; 
}	

void Delete(int hashTable[], int key){
	for (int i = 0; i < 13; i++){
		if (hashTable[i] == key){
			//cant delete an element so just set it to an impossible value
			hashTable[i] = INT_MIN;
		}
	}
}

int main (){
	int key; 
	int size = 13;
	int index; 

	int hashTable[size];

	// Set all the elements of the hash table to 'NULL'
	for (int i = 0; i < 13; i++) {
		hashTable[i] = INT_MIN;
	}
	
	while (key != -1){
		cin >> key;
		//quit and print hash
		if (key != -1 ){
			Insert(hashTable, key);
		}
		else {
			break;
		}
	}
    
	Print (hashTable);  // Print the hash table

	while (key != -2){
		cin >> key;
		//print the index of the element in the hash table
		//if the element is not found print NOT_FOUND 
		if (key != -2){
			int search = Search(hashTable, key);
            if(search != INT_MIN) {                 // If the seardh found the value print its slot
                cout << search << endl;
            }
            else {              // If not print NOT_FOUND
                cout << "NOT_FOUND" << endl;
            }
		}
		else {
			break;
		}
	}

	while (key != -3){
		cin >> key;
		// delete from hash. once the int is found, print the hash
		if (key != -3) {
			Delete(hashTable, key);
		}
        else {
			break;
        }
	}
	Print(hashTable);

	

	return 0;
};
