#include <iostream>
#include <vector>

using namespace std;

/*
-Dado um vetor A de tamanho n, encontre o elemento que se repete mais vezes no vetor.
--Entrada
   A primeira linha contém o inteiro N denotando o número de elementos do vetor A.
   A segunda linha contém inteiros positivos denotando os elementos do vetor A.
--Saída
   Imprima o elemento que mais se repete no vetor e o número de vezes que ele se repete
*/

void ordenar(vector<int> &v, int n){
    for(int i = n-1; i >= 1; i--){  
        for(int k = 0; k <= i-1; k++){
            if(v[k] > v[k+1]){
                swap(v[k], v[k+1]);
            }
        }	
    }
}

int main(){
	int n;
	int aux = 0, cont = 1, i = 0;

	cin >> n;
	vector<int> vetor;
	vector <int> contagem(n,0);
	
	for(int i=0; i<n; i++){
		int numero;
		cin >> numero;
		vetor.push_back(numero);
	}

	ordenar(vetor, n);
	
	for(i=1; i<n; i++){
		if(vetor[i] == vetor[i-1]){
			cont++;
		}else{
			aux = vetor[i-1];
			contagem[aux] = cont; 
			cont = 1;
		}
	}
	aux  = vetor[i-1];
	contagem[aux] = cont;
	
	int maior = 0;
	for(i=0; i<n; i++){
		if(contagem[i] > maior){
			maior = contagem[i];
			aux = i;
		}
	}
	cout << aux << " " << maior; 

}