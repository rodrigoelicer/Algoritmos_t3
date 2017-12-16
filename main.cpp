#include <iostream>
#include <vector>
using namespace std;

int max (int x, int y) { return (x > y)? x : y; }

void printMatriz(vector <vector<int>> &matriz){
	size_t n = matriz.size(), i;

	for( i = 0; i<n ; i++){
		size_t m = matriz[i].size(), j;

		cout << "[";
		for( j = 0; j<m; j++){
			cout << matriz[i][j] << ", ";
		}
		cout << "]" << endl;
	}
}

void lps(vector <vector<int>> &matriz, vector <string> &arr, int n){
	int i;

	string str = arr.back();

	//crea nueva columna
	vector <int> nuevo;
	matriz.push_back(nuevo);

	matriz[n].push_back(1);
	//cout << "n: " << n << endl;
	for( i = 0; i < n; i++ ){
		//cout << "str: " << str << endl;
		//cout << "arr[" << n-i-1 << "]: " << arr[n-i-1] << endl;
		if ( str == arr[n-i-1] && n == 1 ){
			//cout << "entre1" << endl;
			matriz[n].push_back(2);
		}
		else if ( str == arr[n-i-1] ){
			//cout << "entre2" << endl;
			matriz[n].push_back( 2 + matriz[n-1][i-1] );
		}
		else{
			//cout << "entre3" << endl;
			matriz[n].push_back( max(matriz[n][i], matriz[n-1][i]) );
		}
	}
	//printMatriz(matriz);

   return;
}

void printOutput(vector <vector<int>> &matriz, vector <string> &arr, int n){
	int i = n, j = n;
	vector <string> output;

	//cout << "n: " << n << endl;

	if( matriz[i][j] == 1 ){
		output.push_back(arr[0]);
	}

	while( matriz[i][j] != 1 ){
		if( matriz[i][j] > matriz[i-1][j-1] ){
			//cout << "entre1" << endl;
			cout << arr[i];
			output.push_back(arr[i]);
			i--;
			j -= 2;
			//Imprime el char de al medio solo si es distinto.
			if( matriz[i][j] == 1 && arr[i]!=output.back() ){
				cout << arr[i];
			}
		}
		else{
			//cout << "entre2" << endl;
			i--;
			j--;
			if( matriz[i][j] == 1 && arr[i]!=output.back() ){
				cout << arr[i];
			}
		}
	}
	//cout << "wena" << endl;
	for( i = output.size(); i > 0 ; i-- ){
		//cout << "i-1: " << i-1 << endl;
		cout << output[i-1];

	}
	cout << endl << endl;
}

int main(){
	vector <vector<int>> matriz;
	vector <string> arr;
	string str;
	int n = -1;

	while( cin >> str ){
		arr.push_back(str);
		n++;
		lps(matriz, arr, n);
		//printMatriz(matriz);
		printOutput(matriz, arr, n);
	}

	return 0;
}
