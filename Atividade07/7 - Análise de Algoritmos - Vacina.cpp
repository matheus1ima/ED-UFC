#include <iostream>
#include <vector>

using namespace std;

void vacina(int a, vector<int> vacinas, vector<int> pessoas){
    for(int i = 0; i < a; i++){
        for(int j = i + 1; j < a; j++){
            if(vacinas[i] > vacinas[j]){
                swap(vacinas[i], vacinas[j]);
            }
        }
    }
    
    for(int i = 0; i < a; i++){
        for(int j = i + 1; j < a; j++){
            if(pessoas[i] > pessoas[j]){
                swap(pessoas[i], pessoas[j]);
            }
        }
    }
    
    for(int i = 0; i < a; i++){
        if(vacinas[i] >= pessoas[i]){
            if(i == a - 1){
                cout << "Yes" << endl;
            } else {
                continue;
            }
        } else {
            cout << "No" << endl;
            break;
        }
    }
}

int main(){
    int a;
    cin >> a;
    
    vector<int> vacinas;
    vector<int> pessoas;
    
    for(int i = 0; i < a; i++){
        int aux;
        cin >> aux;
        vacinas.push_back(aux);
    }
    
     for(int i = 0; i < a; i++){
        int aux;
        cin >> aux;
        pessoas.push_back(aux);
    }
    
    vacina(a, vacinas, pessoas);
}