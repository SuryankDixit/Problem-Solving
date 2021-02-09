
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);
        Node* t1 = d1;
        Node* t2 = d2;
        Node* curr = head;
        while(curr!=nullptr){
            if(curr->data%2==0){
                t1->next = curr;
                t1 = t1->next;
            }else{
                t2->next = curr;
                t2 = t2->next;
            }
            curr=curr->next;
        }
        t1->next = d2->next;
        t2->next = nullptr;
        return d1->next;
    }
};