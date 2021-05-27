
/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    
    Node* d1=new Node(-1);Node* d2=new Node(-1);Node* d3=new Node(-1);
    Node* t1=d1;
    Node* t2=d2;
    Node* t3=d3;
    while(head){
        if(head->data==0){
            t1->next = head;
            t1=t1->next;
        }
        else if(head->data==1){
            t2->next = head;
            t2=t2->next;
        }
        else if(head->data==2){
            t3->next = head;
            t3=t3->next;
        }
        head=head->next;
    }
    t3->next = nullptr;
    if(t1==d1){
        t2->next = d3->next;
        return d2->next;
    }
    if(t2==d2){
        t1->next = d3->next;
        return d1->next;
    }
    if(t3==d3){
        t1->next = d2->next;
        t2->next = nullptr;
        return d1->next;
    }
    t1->next = d2->next;
    t2->next = d3->next;
    return d1->next;
}
