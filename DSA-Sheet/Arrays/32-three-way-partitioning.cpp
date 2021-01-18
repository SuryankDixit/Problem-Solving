
//User function template for C++

class Solution{   
public:
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        int start=0;
        int end=arr.size()-1;
        for(int i=0;i<=end;){
            int x=arr[i];
            if(x<a){
                swap(arr[i++],arr[start++]);
            }else if(x>b){
                swap(arr[i],arr[end--]);
            }else{
                i++;
            }
        }
    }
};