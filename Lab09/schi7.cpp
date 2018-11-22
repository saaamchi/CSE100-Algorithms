
#include <iostream>
#include <iterator>
#include <list>
#include <string>
using namespace std;

//the purpose of hashFunct is to assign a index where 
//the element would be put on hashtable 
int hashFunct(int input, int hashsize){
	
	return (input%hashsize);
}

void Insert (list<int>&hashTable, int input){

	hashTable.push_front(input);

}

//delete value if it matches in the hash 
void Delete(list<int>&hashTable, int input){

	//the iterator controls the interation of hash but not the things pushed into it
	for (list<int>:: iterator j= hashTable.begin(); j!= hashTable.end(); ++j){
		if (*j == input){
			hashTable.erase(j); 				//erase function deletes one element 
			cout<< input<<" : DELETED"<< endl;
			cout<<"++++++++++++++++++++"<< endl;
			return;
		}
	}

	cout<< input << " : DELETE FAILED" << endl;
	cout<<"++++++++++++++++++++"<< endl;
}

void Print(list<int> hashTable[], int hashsize){
		for (int i = 0; i < hashsize; i++)
		{
				cout << i <<" : ";
				//list<int>:: iterator i = j;
			// we access the hash like an array to print out each individual element
			for(list<int>:: iterator j= hashTable[i].begin(); j!= hashTable[i].end(); ++j)
			{
				cout << *j;
				list<int>:: iterator l= j;

				if (++l != hashTable[i].end())
				{
					cout << "->";
				}
			}
			cout << endl;

		}	

		cout<<"++++++++++++++++++++"<< endl;
}

void Search(list<int>&hashTable, int hashsize, int input){

	int place = 0;

	for (list<int>:: iterator j= hashTable.begin(); j!= hashTable.end(); ++j){
			if(*j == input){
				cout<< input << " : FOUND AT " << hashFunct(input, hashsize)<< "," << place <<endl;
				cout<< "++++++++++++++++++++"<< endl;
				return;
			}
			place++;
				
		}
		cout<< input <<" : NOT FOUND"<<endl;
		cout<< "++++++++++++++++++++"<< endl;
}


int main (){
	int hashsize; 
	int hashval;
	char key;
	int input;

	cin >> hashsize;
	list<int> hashTable[hashsize];

	//hashFunct(value, size);
	//while(1) is an endless loop until it hits 'e'
	while(1){
	cin >> key;
		if(key == 'i')
		{
			cin>> input;
			Insert(hashTable[hashFunct(input,hashsize)], input);
		}

		if(key == 'd')
		{
			cin>> input;
			Delete(hashTable[hashFunct(input,hashsize)], input);
		}
		if(key == 's')
		{
			cin >> input; 
			Search(hashTable[hashFunct(input,hashsize)], hashsize, input);
		}
		if (key == 'o')
		{
			Print(hashTable, hashsize);
		}
		if (key == 'e'){
			break;
		}
	}

	return 0; 
}