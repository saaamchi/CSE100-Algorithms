#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;


//dynamic programming solves each subsubproblem just once and then saves its answer in a table

// struct vectors
// {
// 	vector<int>r;
// 	vector<int>s;
// };



tuple <vector<int>,vector<int>> ext_BottomUp_CutRod(vector<int>p, int n){
	//vector vect;
	vector<int>r(n+1);				//starts at 1 so another value has to be added
	vector<int>s(n+1);				
	r[0] = 0;
	s[0] = 0;
	int q;
	int j;
	
	for (j = 1; j <=n; j++){
		q = INT_MIN;
		for (int i = 0; i < j; i++){
			if(q < p[i] + r[j-i-1]){
				q = p[i] + r[j-i-1];
				s[j] = i+1;
			}
		}
		r[j] = q;
		//cout<<r[j]<<endl;
		//cout<<q<<endl;
	}
	cout << r[n]<<endl;				//print the max value 
	return make_tuple(r,s);   	//return the way in which the rod was cut 
}
void Print(vector<int>p, int n)
{
	vector<int>a;
	vector<int>b;

	tie(a,b) = ext_BottomUp_CutRod(p, n);
	while(n>0)
	{
		cout << b[n]<< " ";
		n = n - b[n];
	}
	cout << -1 << endl;
}	

//referenced http://www.cplusplus.com/forum/beginner/139616/ about tuples
//https://www.geeksforgeeks.org/returning-multiple-values-from-a-function-using-tuple-and-pair-in-c/

int main(){
	
	int length;						//length of rod
	int p;							//prices of each piece
	//int a, b;						//return values 		
	vector<int>a;
	vector<int>b;
	cin >> length;
	vector<int>price;

	for (int i = 0; i < length; i++){
		cin >> p;
		price.push_back(p);
	}

	Print(price,length);



	// tie(a,b) = ext_BottomUp_CutRod(price, length);

	// // while(length > 0)
	// // {
	// 	cout << a[length]<< " ";
	// 	cout << b[length]<< " ";

	// 	length = length - b[length];
	// // }

	// cout << -1 <<endl;
	// // auto max = ext_BottomUp_CutRod(price, length);

	// cout << get<0>(max) << " ";
	// cout << get<1>(max) << " ";
	// cout << "-1" << endl;

	// print(p,n);

return 0;
	
}



