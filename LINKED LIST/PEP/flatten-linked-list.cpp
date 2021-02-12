
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

// Input:
// 3
// 6 5 3
// 163 187 560 577 771 836 
// 163 187 560 771 836 
// 163 187 560

// Its Correct output is:
// 163 163 163 187 187 187 560 560 560 577 771 771 836 836

// And Your Code's output is:
// 163 163 163 187 187 187 560 560

Node* dummy = new Node(-1);

void merge(Node* temp){
  
    
    Node* head=dummy->bottom,*l1=head,*l2=temp;
    
    if(l1->data>l2->data)
        {
            dummy->bottom=l2;
            head=l2;
            l2=l2->bottom;
        }
        else
        {
            dummy->bottom=l1;
            head=l1;
            l1=l1->bottom;;
        }
    
    
    
    while(l1 and l2)
    {
        if(l1->data>l2->data)
            {
                head->bottom=l2;
                l2=l2->bottom;
            }
            else
            {
                head->bottom=l1;
                l1=l1->bottom;
            }
            head=head->bottom;
    }
    if(l1)
        head->bottom=l1;
    else
        head->bottom=l2;
    
}

    
Node *flatten(Node *root)
{
   if(root==nullptr || root->next==nullptr)
    return root;

   
    dummy->bottom = root;
    Node* temp = root->next;
    while(temp!=nullptr){
        merge(temp);
        temp=temp->next;
    }
    return dummy->bottom;
}