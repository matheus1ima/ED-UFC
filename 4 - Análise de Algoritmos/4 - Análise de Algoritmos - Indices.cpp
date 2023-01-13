#include <iostream>
#include <vector>

using namespace std;

void ordenar(int n, vector<int> numeros, vector<int> numeros2) {
    bool status = true;
    vector<int> indices;
    
    for(int j = 0; j < n; j++){
        for(int i = j + 1; i < n; i++){
            if(numeros[i] < numeros[j]){
                swap(numeros[i], numeros[j]);
            }
        }
    }
    
    //for(int i = 0; i < n; i++){
        //cout << numeros[i];
    //}
    
    //cout << " " << endl;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(numeros[i]  == numeros2[j]){
                indices.push_back(j);
            }
        }
    }
    
    cout << indices[0];
    for(int i = 1; i < n; i++){
        cout << " " << indices[i];
    }
    cout << endl;
    
}

int main() {
    int n;
    cin >> n;
    vector<int> numeros;
    vector<int> numeros2;
    
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        numeros.push_back(aux);
    }
    
    for(int i = 0; i < n; i++){
        numeros2.push_back(numeros[i]);
    }
    
    ordenar(n, numeros, numeros2);
}