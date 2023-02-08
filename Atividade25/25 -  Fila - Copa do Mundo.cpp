#include <iostream>
#include <queue>
#include <string>

using std::cout;
using std::cin;
using std::endl;

template <typename T>
class queue{
    private:
        class Node;
        Node * first;
        Node * last;
        int cnt;
    public:
        queue();
        ~queue();
        bool empty();
        void enqueue(T key);
        void dequeue();
        T front();
        int size();
};

template <typename T>
class queue<T>::Node{
    public:
        T key;
        Node * next;
        Node(T key, Node * next = nullptr) : key(key), next(next) {};
};

template <typename T>
queue<T>::queue(){
    first = last = nullptr;
    cnt = 0;
}

template <typename T>
queue<T>::~queue(){
    auto ptr = first;

    while(ptr){
        auto temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    first = last = nullptr;
    cnt = 0;
}

template <typename T>
bool queue<T>::empty(){
    return cnt == 0;
}

template <typename T>
void queue<T>::enqueue(T key){
    auto ptr = new Node(key);

    if(last != nullptr)
        last->next = ptr;
    else
        first = ptr;

    last = ptr;
    cnt++;
}

template <typename T>
void queue<T>::dequeue(){
    if( first != nullptr){
        auto temp = first;
        first = first->next;

        if(first == nullptr)
            last = nullptr;

        delete temp;
        cnt--;
    }
}

template <typename T>
T queue<T>::front(){
    if (first)
        return first->key;
    else
        return T();
}

template <typename T>
int queue<T>::size(){
    return cnt;
}



int main(){
    queue<char> letras;

    letras.enqueue('A');
    letras.enqueue('B');
    letras.enqueue('C');
    letras.enqueue('D');
    letras.enqueue('E');
    letras.enqueue('F');
    letras.enqueue('G');
    letras.enqueue('H');
    letras.enqueue('I');
    letras.enqueue('J');
    letras.enqueue('K');
    letras.enqueue('L');
    letras.enqueue('M');
    letras.enqueue('N');
    letras.enqueue('O');
    letras.enqueue('P');

    while(letras.size() > 1){
        int a, b;

        char primeirotime = letras.front();
        letras.dequeue();
        char segundotime = letras.front();
        letras.dequeue();

        cin >> a;
        cin >> b;
        
        if(a > b){
            letras.enqueue(primeirotime);
        }else{
            letras.enqueue(segundotime);
        }
    }

    cout << letras.front() << endl;
}