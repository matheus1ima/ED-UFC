#include <iostream>
#include <vector>

using namespace std;

void match(int n, int m,  vector<string> consultas, vector<string> buscas){
    
    vector<int> saida(m);
    
    for(int i = 0; i < m; i++){
        int count = 0;
        
        for(int j = 0; j < n; j++){
            if(buscas[i] == consultas [j]){
                count++;
            } 
        }
        
        saida[i] = count;
    }
    
    for(int k = 0; k < m; k++){
        if(k == 0){
            cout << saida[k];
        } else {
            cout << " " << saida[k];
        }
    }
    
    cout << endl;
}

int main(){
    int n;
    int m;
    cin >> n;
    
    vector<string> consultas;
    for(int i = 0; i < n; i++){
        string aux;
        cin >> aux;
        consultas.push_back(aux);
    }
    
    cin >> m;
    
    vector<string> buscas;
    for(int i = 0; i < m; i++){
        string aux;
        cin >> aux;
        buscas.push_back(aux);
    }
    
    match(n, m, consultas, buscas);
}
