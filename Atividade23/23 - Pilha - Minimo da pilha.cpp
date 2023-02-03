#include <iostream>
#include <stack>
using namespace std;

template <class T>

class StackMin{
    private:
        stack <T> data;
        stack <T> min;
    public:
        void push(T x){
            if(data.empty() && min.empty()){
                data.push(x);
                min.push(x);
            }else if(x < min.top()){
                data.push(x);
                min.push(x);
            }else{
                data.push(x);
                min.push(min.top());
            }
        }

        void pop(){
            if(!data.empty() && !min.empty()){
                data.pop();
                min.pop();
            }    
        }

        T getmin(){
            return min.top();
        }

};


int main(){
    int n;
    StackMin <int> s;

    cin >> n;

    for(int i = 0; i < n; i++){
        int op, x;
        cin >> op;
        
        if(op==1){
            cin >> x;
            s.push(x);
        }else if(op==2){
            s.pop();
        }else{
            cout << s.getmin() << endl;
        }
    }
}