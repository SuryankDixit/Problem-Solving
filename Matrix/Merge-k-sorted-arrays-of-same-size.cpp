
// Time Complexity: : O(k) + (k^2)logK
// space : Heap is using O(k) space

typedef pair<int,pair<int,int>> pi;

int *mergeKArrays(int Mat[][N], int k)
{
    int *v = new int[k*k];
    priority_queue<pi,vector<pi> ,greater<pi>> p;
    for(int i=0;i<k;i++){
        p.push(make_pair(Mat[i][0],make_pair(i,0)));
    }
    int l=0;
    while(!p.empty()){
        pi x=p.top();
        int ele=x.first;
        int i=x.second.first;
        int j=x.second.second+1;
        p.pop();
        v[l++]=ele;
        if(i<k && j<k){
            p.push(make_pair(Mat[i][j],make_pair(i,j)));
        }
    }
    return v;
}
