#include <iostream>
#include <vector>

using namespace std;

void iguais(int n, vector<int> colecao1, vector<int> colecao2){
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(colecao1[i] > colecao1[j]){
                swap(colecao1[i], colecao1[j]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(colecao2[i] > colecao2[j]){
                swap(colecao2[i], colecao2[j]);
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(colecao1[i] == colecao2[i]){
            count++;
        } else {
            continue;
        }
    }
    
    if(count == n){
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
}

int main() {
    int n;
    cin >> n ;
    
    vector<int> colecao1;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        colecao1.push_back(aux);
    }
    
    vector<int> colecao2;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        colecao2.push_back(aux);
    }
    
    iguais(n, colecao1, colecao2);
}
