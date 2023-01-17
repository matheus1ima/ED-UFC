#include <iostream>
#include <vector>

using namespace std;

void repetidos(int a, vector<int> numeros){
    
    int contagem = 0;
    
    for(int i = 0; i < a; i++){
        for(int j = i + 1; j < a; j++){
            if(numeros[i] > numeros[j]){
                swap(numeros[i], numeros[j]);
            }
        }
    }
    
    for(int i = 1; i < a; i++){
        if(numeros[i] == numeros[i - 1]){
            contagem++;
        }
    }
    
    cout << contagem << endl;
}

int main(){
    int a;
    vector<int> numeros;
    
    cin >> a;
    
    for(int i = 0; i < a; i++){
        int aux;
        cin >> aux;
        numeros.push_back(aux);
    }
    
    repetidos(a, numeros);
    
}