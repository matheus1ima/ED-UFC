#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void vet(vector<int> vetor, int n){
	if(n==0){
		cout << "vetor vazio" << endl;
	}	
	if(n==1){
		cout << vetor[0] <<" ";
	}else{
		vet(vetor, n-1);
		cout << vetor[n-1] <<" ";
	}
}

void rvet(vector<int> vet, int n){
	if(n==0){
		cout << "vetor vazio" << endl;
	}
	if(n==1){
		cout << vet[0];
		return;	
	}else{
		cout << vet[n-1] << " ";
		rvet(vet, n-1);
	}
}

int sum(vector<int> vet, int n){
	if(n==1) {
		return vet[0];
	}
	else{
		return (vet[n-1] + sum(vet, n-1));
	}
}

int mult(vector<int> vet, int n){ 
	if(n==1){
		return vet[0];
	}
	else
		return vet[n-1] * mult(vet, n-1);	
}

int min(vector<int> vet, int n){
	if(n==1){
		return vet[0];
	}else{
		int m = min(vet, n-1);	
		if(m < vet[n-1]){
			return m;
		}else{
			return vet[n-1];	
		}
	}
}

void inv(vector<int> vetor, int inicio, int fim){
	int i=0;
	if(inicio < fim){
		i = vetor[inicio];
		vetor[inicio] = vetor[fim];
		vetor[fim] = i;
		inv(vetor, inicio+1, fim-1);
	}
	if(fim<=inicio){
		vet(vetor, vetor.size());
		return;
	}
}

int main(){
	string line;
	getline(cin, line);
	stringstream ss(line);
	vector<int> vetor;
	int value;
	
	while(ss >> value)
	    vetor.push_back(value);

	cout <<"vet : [ ";
	vet(vetor, vetor.size());
	cout <<"]";
	cout <<"\nrvet: [ ";
	rvet(vetor, vetor.size());
	cout <<" ]";
	cout << "\nsum : "<< sum(vetor, vetor.size()) << endl;
	cout << "mult: "<< mult(vetor, vetor.size()) << endl;
	cout << "min : " << min(vetor, vetor.size()) << endl;
	cout <<"inv : [ ";
	inv(vetor, 0, vetor.size()-1);
	cout << "]\n";	
}