class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        if(!root1||!root2)return 0;
        
        stack<Node*> st1,st2;
        Node* top1,*top2;
        int cnt=0;
        
        while(1){
            while(root1){
                st1.push(root1);
                root1=root1->left;
            }
            while(root2){
                st2.push(root2);
                root2=root2->right;
            }
            
            if(st1.empty()||st2.empty()) break;
            
            top1=st1.top();
            top2=st2.top();
            
            if(top1->data+top2->data==x){
                cnt++;
                st1.pop();
                st2.pop();
                root1=top1->right;
                root2=top2->left;
            }
            
            else if(top1->data+top2->data < x){
                st1.pop();
                root1=top1->right;
            }
            
            else{
                st2.pop();
                root2=top2->left;
            }
        }
        return cnt;
    }
};
