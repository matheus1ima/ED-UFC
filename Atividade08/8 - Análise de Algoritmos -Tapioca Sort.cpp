#include <iostream>
#include <vector>

using namespace std;
 
void printvector(vector<int> &v, int n){
	n = v.size();
	if(n==0) return;
	cout << v[0];
	for(int i=1; i<n; i++){
		cout << " "<< v[i];
	}
	cout <<"\n";	
}
 
int findMax(vector<int> &v, int n){
	int max = 0;
	for (int i = 0; i<n; i++)
	    if (v[i] > v[max]){
	        max = i;
	    }
	return max;	
} 

void flip(vector<int> &v, int n){
	int aux = 0;
	int comeco = 0;
	while(comeco < n){
		swap(v[comeco], v[n]);
		comeco ++;
		n--; 	
	}
}  

void tapioca_sort(vector<int> &resposta, vector<int> &posicoes, vector<int> &v, int n){
	int i=n; 
	for(i = n; i>1; i--){
		int max = findMax(v, i);
		cout << "numeros: ";printvector(v, n);
		if(max != i-1 && max!= 0){
			cout << "\nmax: "<<max<<endl;
			cout << "posicao[max]: "<< posicoes[max]<<endl;
			resposta.push_back(posicoes[max]);
			flip(v, max);
			flip(v, i-1);
			cout << "resposta: "<<endl; printvector(resposta, 7);	 
			cout << "posciao[i-1]: "<< posicoes[i-1]<<endl;  
			resposta.push_back(posicoes[i-1]);
			cout << "resposta: "<<endl; printvector(resposta, 7);	
		}else if(max==0){
			flip(v, i-1);
			resposta.push_back(posicoes[i-1]);
		}
		
	}		
}

void ordenar(vector<int> &v, int n){
    for(int i=n-1; i>=1; i--){  
        for(int k=0; k<=i-1; k++){
            if(v[k] < v[k+1]){
                swap(v[k], v[k+1]);
            }
        }	
    }
}

int main(){
	int n;
	cin >> n;
	
	vector<int> posicoes;
	vector<int> numeros;
	vector<int> resposta;
	for(int i=0; i<n; i++){
		int numero;
		cin >> numero;
		numeros.push_back(numero);
	}

	cout << "numeros: "; printvector(numeros, n);
	
	for(int i=0; i<n; i++){
    	posicoes.push_back(numeros[i]);
	}	
	
	ordenar(posicoes, n);
	
	tapioca_sort(resposta, posicoes, numeros, n);
	
	cout << "numeros: "; printvector(numeros, n);
	cout << "posicoes: "; printvector(posicoes, n);
	resposta.push_back(0);
	int t = resposta.size();
	cout << "resposta: "; printvector(resposta, t);
	
    return 0;
}