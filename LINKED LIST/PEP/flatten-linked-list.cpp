#include<bits/stdc++.h>

//Node structure  used in the program
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

void merge(Node* l2){
    
    
    Node* l1 = dummy->bottom;
    Node* temp = dummy;
    if(l1&&!l2)
        return;
    if(l2&&!l1)
        return;
    
    while(l1&&l2){
        if(l1->data==l2->data){
            temp->bottom = l1;
            l1=l1->bottom;
            temp->bottom->bottom = l2;
            l2=l2->bottom;
            temp=temp->bottom->bottom;
        }else if(l1->data < l2->data){
            temp->bottom= l1;
            l1=l1->bottom;
            temp=temp->bottom;
        }else{
            temp->bottom= l2;
            l2=l2->bottom;
            temp=temp->bottom;
        }
    }
    while(l1){
        temp->bottom= l1;
        l1=l1->bottom;
        temp=temp->bottom;
    }
    while(l2){
        temp->bottom= l2;
        l2=l2->bottom;
        temp=temp->bottom;
    }
    temp->bottom = nullptr;
    return;
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