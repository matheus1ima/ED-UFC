#include <iostream>
#include <vector>

using namespace std;

void printvector(vector<int> &arr, int a){
	if(a == 0) return;
	cout << "[" << arr[0];
	for(int i = 1; i < a; i++){
		cout << "," <<arr[i];
	}
	cout << "]";
}

int selection_sort(vector<int> &trocas, int a){
	int cont = 0;
	for(int i = 0; i < a; i++){
		int min = i;
		for(int j = i + 1; j < a; j++){
			if(trocas[j] < trocas[min]){
				min = j;
			}
		}
			if(trocas[i] != trocas[min]){
			swap(trocas[i], trocas[min]);
			cont ++;
		}
	}
	return cont;
}

int main(){
	int a;
	cin >> a;
	vector<int> trocas(a);
	
	for(int i = 0; i < a; i++){
		cin >> trocas[i];
	}
	
	int ok = selection_sort(trocas, a);
	cout << ok << endl;
}