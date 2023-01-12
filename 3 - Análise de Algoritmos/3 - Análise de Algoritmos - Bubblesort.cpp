#include <iostream>
#include <vector>

using namespace std;

int bubblesort(vector<int> numeros, int a){
    int contagem = 0;
    bool status = true;
    
    while(status){
        status = false;
        contagem++;
        for(int i = 0; i < a - 1; i++){
            if(numeros[i] > numeros[i + 1]){
                swap(numeros[i], numeros[i + 1]);
                status = true;
            }
        }
    }
    
    return contagem;
}

int main(){
    int a;
    vector<int> numeros;
    cin >> a;
    
    for(int i = 0; i < a; i++){
        int valor;
        cin >> valor;
        numeros.push_back(valor);
    }
    
    int resultado = bubblesort(numeros, a);
    cout << resultado << endl;
}