
/*
138. Copy List with Random Pointer
 CLONE LINKED LIST WITH RANDOM POINTER.
*/

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
        
        unordered_map<Node*,int>m;
        Node* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            m[temp]=count;
            count++;
            temp=temp->next;
        }
        temp=head;
        Node* new_head=NULL;
        vector<Node*> v;
        while(temp!=NULL)
        {
            Node* ptr=new Node(temp->val,NULL,NULL);
            if(new_head==NULL){
                new_head=ptr;
                cout<<"hi"<<" ";
            }
            
            v.push_back(ptr);
            count--;
            temp=temp->next;
        }
        temp=head;
        int i=0;
        while(temp!=NULL)
        {
            if(i==v.size()-1)
                v[i]->next=NULL;
            else
                v[i]->next=v[i+1];
            
            if(temp->random!=NULL){
            int pos=m[temp->random];
            v[i]->random=v[pos];
            }
            
            i++;
            temp=temp->next;
        }
        return new_head;
    }
};