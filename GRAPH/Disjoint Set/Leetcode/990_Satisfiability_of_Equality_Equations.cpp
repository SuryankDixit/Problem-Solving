class Solution {
public:
    vector<int> parent;
    
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    
    void unite(int x,int y){
        int s1 = find(x);
        int s2 = find(y);
        
        // cout<<s1<<" "<<s2<<endl;
        if(s1!=s2)
            parent[s1]=s2;
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        parent.resize(27);
        for(int i=0;i<=26;i++){
            parent[i] = i;
        }
        
        for(int i=0; i<equations.size(); i++){
            if(equations[i][1]=='='){
                
                int x = equations[i][0]-'a';
                int y = equations[i][3]-'a';
                
                unite(x,y);
            }
        }
        
        // for(int i=0;i<26;i++)
        //     cout<<parent[i]<<" ";
        
        for(int i=0; i<equations.size(); i++){
            if(equations[i][1]=='!'){
                
                int x = equations[i][0]-'a';
                int y = equations[i][3]-'a';
                if(find(x)==find(y))
                    return false;
            }
        }
        return true;
    }
};
