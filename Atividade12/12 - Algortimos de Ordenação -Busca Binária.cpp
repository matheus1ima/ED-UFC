#include <iostream>
#include <vector>

using namespace std;

void busca_binaria(int a, int b, vector<int> ordenado, int item, int i){
    
    int inicio = 0;
    int fim = a - 1;
    int contador = 0;
  
    while(inicio <= fim){
        int meio = (inicio + fim)/2;
        contador++;
        if(ordenado[meio] == item){
            break;
        } else {
            if(ordenado[meio] > item){
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }
    }
  
    if(i < (b - 1)){
        cout << contador << " ";
    } else {
        cout << contador << endl;
    }
}

int main(){
    
    int a;
    int b;
    int item;
    vector<int> ordenado;
    vector<int> encontre;
    
    cin >> a;
    cin >> b;
    
    for(int i = 0; i < a; i++){
        int aux;
        cin >> aux;
        ordenado.push_back(aux);
    }
    
    for(int i = 0; i < b; i++){
        int aux;
        cin >> aux;
        encontre.push_back(aux);
    }
    
    for(int i = 0; i < b; i++){
        item = encontre[i];
        busca_binaria(a, b, ordenado, item, i);
    }
    
}
