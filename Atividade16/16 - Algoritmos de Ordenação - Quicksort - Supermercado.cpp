#include <iostream>
#include <vector>

using namespace std;

class Product {
    private:
    string name;
    int price;

    public:
    Product(string n, int p) {
        name = n;
        price = p;
    }
    bool operator<(const Product & a){
        if( price != a.price){
            return price < a.price;
        }else{
            return name < a.name;
        }
    }
    friend ostream& operator<<(ostream& os, const Product& p);
};

ostream& operator<<(ostream& os, const Product& p){
    os << p.name;
    return os;
}


void ler(vector<Product> &p, int n){
	for(int i=0; i<n; i++){
		string nome;
		int preco;
		cin >> nome >> preco;
		Product produto(nome, preco);
		p.push_back(produto);
	}	
}

void printvector(vector<Product> & arr, int n){
	if(n==0) return;
	cout << arr[0];
	for(int i=1; i<n; i++){
		cout << " "<<arr[i];
	}
	cout <<"\n";
}

void ordena(vector<Product> &v){
	int n = v.size();
	
	for(int i=0; i<n; i++){
		for(int j=n-1; j>i; j--){
			Product p1 = v[i];
			Product p2 = v[j];
			if(p2 < p1){
				swap(v[i], v[j]);
			}
		}
	}	
}

int main(){
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	vector<Product> fila1;
	vector<Product> fila2;
	vector<Product> prod;
	ler(fila1, n);
	ler(fila2, m);
	
	ordena(fila1);
	ordena(fila2);
	
	for(int i=0; i<p; i++){
		Product p = fila1[i];
		prod.push_back(p);
	}
	for(int i=0; i<q; i++){
		Product p = fila2[i];
		prod.push_back(p);
	}	
	
	ordena(prod);

	printvector(prod, p+q);
}