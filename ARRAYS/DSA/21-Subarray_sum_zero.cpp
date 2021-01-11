//Complete this function
bool subArrayExists(int v[], int n)
{
    unordered_map<int,int> m;
    m[0]=1;
    int x=0;
    for(int i=0;i<n;i++){
        
        x+=v[i];
        if(m.find(x)!=m.end())
            return true;
        else
            m[x]=i;
    }
    return false;
}

