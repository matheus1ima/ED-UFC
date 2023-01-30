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

 

ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head;
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


int getMiddle(ListNode *head){
    int cont = -1;
    
    ListNode * slow = head;
    ListNode * fast = head;
    
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cont++;
    
    if(cont%2 == 0){
        cont = cont / 2;
    }else{
        cont = cont / 2;
    }
    
    for(int i = 0; i <= cont; i++){ 
        if(fast == nullptr)
            return 0 ;   
        fast = fast->next;
    }

    while(fast != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    return slow->val;
}   



int main(){
    
    ListNode * head = readList();
    
    cout << getMiddle(head) << endl;

    
    return 0;    
}