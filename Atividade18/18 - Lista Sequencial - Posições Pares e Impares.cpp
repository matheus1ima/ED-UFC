#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

int kthElement(ListNode * head, int k){

    if(head == nullptr)
        throw std::runtime_error("out of range");
    else if(k == 1)
        return head->val;
    else
        return kthElement(head->next, k-1);

}

ListNode * insert_back(ListNode * head, int val){
    if(head == nullptr){
        return new ListNode(val);
    
    }else{
        head->next = insert_back(head->next, val);
        return head;
    }
}

ListNode * removeElement(ListNode* head, int val) {

    if(head == nullptr){
    	return nullptr;
	}else{
		if(head->val == val){
			auto ptr = head->next;
			delete head;
			return removeElement(ptr, val);
		}else{
			head->next = removeElement(head->next, val);
			return head;
		}
	}
}

ListNode* oddEvenList(ListNode* head){
    int cont = 0;
    
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cont++;
    
    int aux = 0;
    for(int i = 1; i <= cont; i++){
        if( i%2==0){
            int valor = kthElement(head, i-aux);
            head = removeElement(head, valor);
            head = insert_back(head, valor);
            aux++;
        }
    }
    
    return head;
}


int main(){
    int n;
    ListNode * head= nullptr;
    cin >> n;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
        int x;
        cin >> x;
        if( i == 0){
            head = new ListNode(x);
            ptr = head;
        }else{
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    head = oddEvenList(head);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}