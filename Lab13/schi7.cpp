#include <iostream>
#include <climits>
#include <tuple>
using namespace std; 

void Print(int** s, int i, int j){
  if(i == j){
    cout<< "A" << i - 1;
  }
  else {
    cout<<"(";
      Print(s, i, s[i][j]);
      cout << ".";
      Print(s, s[i][j]+1, j);
      cout <<")";
  }
}

void MatrixChainOrder (int arr[],int n){
	int j, i;

	//double pointer is a pointer to pointer 
  int** m = new int*[n];

  for (int z = 0; z < n; ++z){
    m[z] = new int[n];
  }

  int** s = new int*[n];

  for (int z = 0; z < n; ++z){
    s[z] = new int[n];
  }

  for (i = 0; i < n; ++i){
    m[i][i] = 0;
  }

	for (int l = 2; l < n; l++){			//k is chain length
		for (i = 1; i < (n - l + 1); i++){        //maybe <=
			j = i + l - 1;
			m[i][j] = INT_MAX;

			for (int k = i; k <= j - 1; k++){         //maybe <=
				int q = m[i][k] + m[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
        if(q < m[i][j]){
          m[i][j] = q;
          s[i][j] = k;
        }
			}
		}
	}
  //return make_tuple(m,s);
  cout << m[1][n-1] << endl;
  
  Print(s, 1, n-1);
  cout << endl;
}

int main(){

  int i = 0;

	int matrices = 0;
  
  cin >> matrices;
  int arrayP[matrices+1];

	while (i < matrices+1){
		cin >> arrayP[i]; 
    //tie(arrayM,arrayS) = MatrixChainOrder(arr, matrices);
    i++;
	}

  MatrixChainOrder(arrayP, matrices+1);
	return 0; 
}


