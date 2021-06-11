vector<int> findUnion(int a1[], int a2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        int i=0;int j=0;
        while(i<n&&j<m){
            // cout<<a1[i]<<" "<<a2[j]<<endl;
            if(a1[i]==a2[j]){
                if(ans.size()>0 && ans[ans.size()-1]!=a1[i])
                    ans.push_back(a1[i]);
                else if(ans.size()==0)
                    ans.push_back(a1[i]);
                i++;j++;
            }else if(a1[i]>a2[j]){
                if(ans.size()>0 && ans[ans.size()-1]!=a2[j])
                    ans.push_back(a2[j]);
                else if(ans.size()==0)
                    ans.push_back(a2[j]);
                j++;
            }else if(a1[i]<a2[j]){
                if(ans.size()>0 && ans[ans.size()-1]!=a1[i])
                    ans.push_back(a1[i]);
                else if(ans.size()==0)
                    ans.push_back(a1[i]);
                i++;
            }
        }
        while(i<n){
            if(ans.size()>0 && ans[ans.size()-1]!=a1[i])
                ans.push_back(a1[i]);
            else if(ans.size()==0)
                ans.push_back(a1[i]);
            i++;
        }
        while(j<m){
           if(ans.size()>0 && ans[ans.size()-1]!=a2[j])
                ans.push_back(a2[j]);
            else if(ans.size()==0)
                ans.push_back(a2[j]);
            j++;
        }
        return ans;
    }