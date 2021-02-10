/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        
        Node* temp = head;
        while(temp!=nullptr){
            Node* t = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = t;
            temp = temp->next->next;
        }
        
        temp=head;
        while(temp!=nullptr){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            temp=temp->next->next;
        }
        
        Node* d1 = new Node(-1);
        Node* t = d1;
        temp = head;
        while(temp){
            t->next = temp->next;
            t=t->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        return d1->next;
    }
};