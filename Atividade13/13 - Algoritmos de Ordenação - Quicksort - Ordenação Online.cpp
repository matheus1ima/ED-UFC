#include <iostream>
#include <vector>

using namespace std;

void printar(vector<int> numeros, int aux){
    
    for(int j = 0; j < numeros.size(); j++){
        for(int i = j + 1; i < numeros.size(); i++){
            if(numeros[i] < numeros[j]){
                swap(numeros[i], numeros[j]);
            }
        }
    }
    
    cout << numeros[aux] << endl;
}

int main() {
    int solicita;
    cin >> solicita;
    int numero;
    vector<int> numeros;
    int aux;
    
    for(int m = 0; m < solicita; m++){
        cin >> numero;
        if(numero == 1){
            cin >> aux;
            numeros.push_back(aux);
        }else if(numero == 2){
            cin >> aux;
            printar(numeros, aux);
        }
    }
}
