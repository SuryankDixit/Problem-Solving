
class Solution {
private:
public:
	int minSwaps(vector<int>&arr){
	    int N=arr.size();
	    unordered_map<int,int> m;
        priority_queue<int, vector<int>, greater<int> > p;
        
        for(int i=0;i<N;i++){
            p.push(arr[i]);
            m[arr[i]]=i;
        }
        
        int count =0;
        int num1,num2,idx1,idx2;
        int k=0;
        
        for(int i=0;i<N;i++){
            num1=p.top();
            p.pop();
            idx1=m[num1];
            if(idx1==k)
                k++;
            else{
                count++;
                num2=arr[k];
                swap(arr[k],arr[idx1]);
                m[num2]=idx1;
                k++;
            }
        }
        return count;
    	}
};