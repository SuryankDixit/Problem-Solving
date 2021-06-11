class Solution{
    public:
    
    static bool comp(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2){
        if(p1.first > p2.first){
            return false;
        }else if(p1.first == p2.first && p1.second.first < p2.second.first){
            return false;
        }else if(p1.first == p2.first && p1.second.first == p2.second.first && p1.second.second > p2.second.second){
            return false;
        }
        return true;
    }
    
    void customSort (int phy[], int chem[], int math[], int N)
    {
        vector<pair<int,pair<int,int>>> p;
        for(int i=0;i<N;i++){
            p.push_back({phy[i],{chem[i],math[i]}});
        }
        sort(p.begin(),p.end(),comp);
        for(int i=0;i<N;i++){
            phy[i]=p[i].first;
            chem[i]=p[i].second.first;
            math[i]=p[i].second.second;
        }
    } 
};