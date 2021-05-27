//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> p,neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            neg.push_back(arr[i]);
	        }else{
	            p.push_back(arr[i]);
	        }
	    }
	    int i,j,k;
	    i=j=k=0;
	    for(i=0;i<n;){
	        if(k<p.size()){
	            arr[i++]=p[k++];
	        }
	        if(j<neg.size()){
	           arr[i++]=neg[j++];
	        }
	    }
	}
};
