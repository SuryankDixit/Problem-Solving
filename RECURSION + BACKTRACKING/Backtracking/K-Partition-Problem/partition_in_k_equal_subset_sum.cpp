#include <bits/stdc++.h>
using namespace std;


void partition_in_k_equal_subset_sum(int index, vector<int> &arr, vector<int> &subsets, vector<vector<int>> &partition, int ssf){

    int k = subsets.size();
    

    if(index==arr.size()){

        int flag = 0;
        
        if(ssf == k){
            for(int i=0;i<k-1;i++){
                if(subsets[i]!=subsets[i+1]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                int total_sum =0;
                for(auto x: partition){
                    for(int i=0;i<x.size();i++){
                        cout<<x[i]<<" ";
                        total_sum += x[i];
                    }
                    cout<<endl;
                }
                cout<<total_sum<<endl<<endl;
            }
        }
        return;
    }
    
    for(int i=0;i<k;i++){

        if(partition[i].size()>0){

            partition[i].push_back(arr[index]);
            subsets[i] += arr[index];
            partition_in_k_equal_subset_sum(index+1,arr,subsets,partition,ssf);
            partition[i].pop_back();
            subsets[i] -= arr[index];

        }else{

            partition[i].push_back(arr[index]);
            subsets[i] += arr[index];
            partition_in_k_equal_subset_sum(index+1,arr,subsets,partition,ssf+1);
            partition[i].pop_back();
            subsets[i] -= arr[index];
            break;
        }
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  
    int n ,k;
    cin>>n>>k;

    vector<int> v(n);

    int total_sum=0;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
        total_sum += v[i];
    }

    if(total_sum % k != 0 || k>n){
        cout<<"Partition is not Possible";
        return 0;
    }

    int each_set_sum = total_sum/k;

    vector<int> subset_sum(k,0);
    vector<vector<int>> partition(k);
    int subsets_filled_so_far = 0;

    partition_in_k_equal_subset_sum(0,v,subset_sum,partition,subsets_filled_so_far);

    return 0;
}


// 12  k = 2,3,4,5
// 7 3 5 12 2 1 5 3 8 4 6 4




// input 2
// 5 3
// 2 1 4 5 6

// output
// 2 4 
// 1 5 
// 6 
