
class Solution{
  public:
    // This function returns true if str1 and str2 are ismorphic
    // else returns false
    bool areIsomorphic(string s1, string s2)
    {
        int n1=s1.size();
        int n2=s2.size();
        if(n1!=n2)
            return false;
        
        bool visited[256]={false};
        int v[256];
        memset(v,-1,sizeof(v));
    
        for(int i=0;i<n1;i++){
            if(v[s1[i]]==-1){
                if(visited[s2[i]]==true)
                    return false;
                visited[s2[i]] = true;
                v[s1[i]]=s2[i];
            }
            else if(v[s1[i]]!=s2[i])
                return false;
        }
        return true;
    }
};