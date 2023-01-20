#include <iostream>
#include <vector>

using namespace std;

void fila(int n, vector<int> deN, int m, vector<int> deM){
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(deM[i] == deN[j]){
                deN[j] = 0;
            } else {
                continue;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(deN[i] != 0){
            cout << deN[i] << " ";
        } else {
            continue;
        }
    }
    
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> deN;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        deN.push_back(aux);
    }
    
    int m;
    cin >> m;
    
    vector<int> deM;
    for(int i = 0; i < m; i++){
        int aux;
        cin >> aux;
        deM.push_back(aux);
    }
    
    fila(n, deN, m, deM);
}