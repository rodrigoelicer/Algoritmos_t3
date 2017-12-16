#include <iostream>
#include <vector>
using namespace std;

#include <string>
#include <sstream>

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
	cout << endl;
}

void printOutput(vector <vector<int>> &matriz, string arr){

	unsigned int n = matriz.size()-1;
	unsigned int i = n, j = n;
	vector <char> output;

	//cout << "n: " << n << endl;
	if( matriz[i][j] == 1 ){
		output.push_back(arr[0]);
	}

	while( matriz[i][j] != 1 ){
		//cout << "i: " << i << endl;
		//cout << "j: " << j << endl;
		//cout << "matriz[i][j]: " << matriz[i][j] << endl;
		//cout << "matriz[i-1][j-2]: " << matriz[i-1][j-2] << endl;
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
	for( i = output.size(); i > 0 ; i-- ){
		//cout << "i-1: " << i-1 << endl;
		cout << output[i-1];

	}
	cout << endl << endl;
}

void lps(string str){

	unsigned int n = str.length();
	vector <vector<int>> matriz;
	unsigned int i, j;

	//cout << "n: " << n << endl;

	for( i = 0; i<=n-1 ;i++){
		//cout << "i: " << i << endl;

		vector <int> nuevo;
		matriz.push_back(nuevo);
		matriz[i].push_back(1);

		char chr = str[i];

		//cout << "chr: " << chr << endl;

		for( j = 1; j<=i; j++){
			//cout << "j: " << j << endl;
			//cout << "str["<<i-j<<"]: " << str[i-j] << endl;

			if ( chr == str[i-j] && j == 1 ){
				//cout << "entre1" << endl;
				matriz[i].push_back(2);
			}
			else if ( chr == str[i-j] ){
				//cout << "entre2" << endl;
				matriz[i].push_back( 2 + matriz[i-1][j-2] );
			}
			else{
				//cout << "entre3" << endl;
				matriz[i].push_back( max(matriz[i][j-1], matriz[i-1][j-1]) );
			}
		}
		//printMatriz(matriz);
		//printOutput(matriz,str);

	}
	cout << matriz[i-1][i-1] << endl;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);

	string str;
	while( cin >> str ){
		lps(str);
	}

	return 0;
}
