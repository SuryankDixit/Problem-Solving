class Solution {
public:
    string addBinary(string a, string b) {
        int n1,n2;
        n1= a.size()-1;
        n2 = b.size()-1;
        
        int carry=0;
        string ans="";
        int sum=0;
        while(n1>=0 || n2>=0 || carry){
            sum=carry; 
            if(n1>=0)
               sum += a[n1--]-'0';
            if(n2>=0)
                sum+= b[n2--]-'0';
            ans += to_string(sum%2);
            // cout<<ans<<" ";
            carry= sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};