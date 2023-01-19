#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    int n = vet.size();
	vector<int> temp(n);
	
	for(int i = 0; i < n; i++){
		int m = (i + nrot) % n;
		temp[m] = vet[i];
	}
	
	for(int i = 0; i < n; i++){
		vet[i] = temp[i];
	}
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}
