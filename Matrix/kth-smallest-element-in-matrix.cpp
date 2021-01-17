typedef pair<int,pair<int,int>> pi;
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<pi,vector<pi>,greater<pi>> p;
    for(int i=0;i<n;i++){
        p.push(make_pair(mat[i][0],make_pair(i,0)));
    }
    vector<int> v(k,0);
    int a=0;
    while(!p.empty()){
        pi x=p.top();
        p.pop();
        int ele= x.first;
        int i = x.second.first;
        int j = x.second.second+1;
        v[a++]=ele;
        if(a==k)
            break;
        if(j<n){
            p.push(make_pair(mat[i][j],make_pair(i,j)));
        }
    }
    return v[a-1];
}
