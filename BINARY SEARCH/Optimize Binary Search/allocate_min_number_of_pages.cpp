// O(nlogn) time complexity;


bool isValid(vector<int> &v,int s,int mid){
    int count =1;
    int sum = 0;
   
    for(int i=0;i<v.size();i++){
        // sum=sum+v[i];
        if( (sum+v[i]) > mid){
            count++;
            sum=v[i];
            // cout<<count<<" ";
            if(count>s)
                return false;
        }else{
            sum+=v[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    
    if(B> A.size())
        return -1;
    int start =0;
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        start = max(start,A[i]);
    }
    int ans = -1;
    int end = sum;
    while(start <= end){
        int mid = start +(end-start)/2;
        if(isValid(A,B,mid) == true){
            // cout<<mid<<endl;
            ans = mid;
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return ans;
}
