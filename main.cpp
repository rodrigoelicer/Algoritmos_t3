#include <iostream>
#include <vector>
using namespace std;

//Función que retorna el máximo entre 2 valores.
int max (int x, int y){
	return (x > y) ? x : y;
}

//Función que recorre un string, crea una matriz[n][n] y obtiene el valor de la
//subsecuencia palíndroma más grande. Lo hace en tiempo O(n²)
void lps(string str){

	//Se crea un vector para el string dado.
	vector <vector<int>> matriz;
	unsigned int n = str.length();
	unsigned int i, j;

	//Se recorre el string
	for( i = 0; i<=n-1 ;i++){
		//Por cada letra se agrega un nuevo vector al vector matriz,
		//generando una matriz.
		vector <int> nuevo;
		matriz.push_back(nuevo);
		//Se agrega el valor base que indica que son la misma letra
		matriz[i].push_back(1);
		//Char que se va a comparar con todos los otros char que le anteceden.
		char chr = str[i];
		//se compara el char str[i] con los distintos char[i-j]
		//Va desde el final hacia el principio.
		for( j = 1; j<=i; j++){
			//Caso base donde el string puede tener largo 2
			if ( chr == str[i-j] && j == 1 ){
				matriz[i].push_back(2);
			}
			//Caso donde se suma 2 más el largo del substring anterior.
			else if ( chr == str[i-j] ){
				matriz[i].push_back( 2 + matriz[i-1][j-2] );
			}
			//Caso donde no hay match y se toma el máximo de lo que ya hay.
			else{
				matriz[i].push_back( max(matriz[i][j-1], matriz[i-1][j-1]) );
			}
		}
	}
	//Se imprime el último valor que indica el palíndromo más largo.
	cout << matriz[i-1][i-1] << endl;
	matriz.clear();
	return;
}

int main(){
	string str;
	//Recibe inputs hasta que el usuario desee.
	//Con ctrl+D se hace EOF. ctrl+C se le hace kill
	while( cin >> str ){
		//Función que revisa el largo de la subsecuencia palíndroma más grande.
		lps(str);
	}
	return 0;
}
