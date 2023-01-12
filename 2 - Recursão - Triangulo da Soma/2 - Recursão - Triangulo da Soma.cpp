#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int calc(int ** t, int i, int j, int n){
	if(i == n-1) {
		return t[i][j];
	}
	else{
		t[i][j] = calc(t,i+1, j, n) + calc(t, i+1, j+1, n);
		return t[i][j];
	}
}

int main(){
	string line;
	getline(cin, line);
	stringstream ss(line);
	int value;
	vector<int> aux;
	while (ss >> value){
		aux.push_back(value);
	} 
	int n = aux.size();

	int **t;
	t = new int *[n];
	for(int i=0; i<n; i++)
		t[i] = new int [n];
		
	for(int i=0;i<n;i++)//coluna
		t[n-1][i] = aux[i];
		
				
	calc(t, 0, 0, n);	
	
	for(int i=0; i<n; i++){
		cout << "[" << " ";
		for(int j=0; j<=i; j++){
			cout << t[i][j] << " " ;
		}
		cout << "]\n";
	}
}