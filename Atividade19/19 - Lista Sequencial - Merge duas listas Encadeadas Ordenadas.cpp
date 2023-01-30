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

void ordena(ListNode* head){
    
    if(head == nullptr)
        return;

    for(ListNode * ptr = head; ptr->next != nullptr; ptr = ptr->next){
        ListNode * min = ptr;
        for(ListNode * ptr1 = ptr->next; ptr1 != nullptr; ptr1 = ptr1->next){
            if(ptr1->val < min->val){
                min = ptr1;
            }
        }
        swap(ptr->val, min->val);
    }

}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode * head;
    int i = 0; 
    ListNode * aux; 
    
    for(ListNode * ptr = l1; ptr != nullptr; ptr = ptr->next){
        if( i == 0){
            head = new ListNode(ptr->val);
            aux = head;
            i++;
        }else{
            aux->next = new ListNode(ptr->val, nullptr);
            aux = aux->next;
        }
    }
    
    for(ListNode * ptr = l2; ptr != nullptr; ptr = ptr->next){
        if( i == 0){
            head = new ListNode(ptr->val);
            aux = head;
            i++;
        }else{
            aux->next = new ListNode(ptr->val, nullptr);
            aux = aux->next;
        }
        
    }
        
    ordena(head);
  
    return head;
}

ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head = nullptr;
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

    return head;

}


int main(){
    
    ListNode * list1 = readList();
    ListNode * list2 = readList();
    ListNode * head = mergeTwoLists(list1, list2);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}