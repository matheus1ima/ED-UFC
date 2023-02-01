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


ListNode * intersectionList(ListNode * head1, ListNode * head2){
    ListNode * res;
    int i = 0;
    
    for(ListNode * ptr = head1; ptr != nullptr; ptr = ptr->next){
        ListNode * aux;
        for(ListNode * ptr1 = head2; ptr1 != nullptr; ptr1 = ptr1->next){
            if(ptr->val == ptr1->val){
                if( i == 0 ){
                    res = new ListNode(ptr->val);
                    aux = res;
                    i++;
                }else{
                    if(ptr->val != res->val){
                        aux->next = new ListNode(ptr->val, nullptr);
                        aux = aux->next;
                    }
                }
                break;
            }
        }
    }
    return res;
}


void printList(ListNode * head){
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
}



int main(){
    
    ListNode * head1 = readList();
    ListNode * head2 = readList();
     
    ListNode * res = intersectionList(head1, head2);


    printList(res);

    return 0;    
}
