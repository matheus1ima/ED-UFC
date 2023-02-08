#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void prox_maior(stack<int> &p, vector<int> v, vector<int> &r, int n){   
    for(int i=n; i<n+1; i++){
        int j = 0;
        while( j < p.size() ){
            int x = p.top();
            if( v[x] < v[i] ){
                r[p.top()] = i;
                p.pop();
            }else{
                if(p.top() != i){
                    p.push(i);
                }else{
                    return;
                }
            }
        }
        p.push(i);
    }
}


int main(){
    int n;
    vector<int> v;
    stack<int> pilha;
    
    cin >> n;
    vector<int> r(n);

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    pilha.push(0);
    for(int i=1; i<n; i++){
        prox_maior(pilha, v, r, i);
    }
    
    while( !pilha.empty() ){
        int x = pilha.top();
        r[x] = -1;
        pilha.pop();
    }
    
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << r[i];
        } else {
            cout << r[i] << " ";
        }
    }
    
    cout << "\n";
    
    return 0;
}