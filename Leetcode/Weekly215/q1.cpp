class OrderedStream {
public:
    vector<string> v;
    int ptr;
    OrderedStream(int n) {
        v.resize(n+1,"");
        ptr=1;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> temp;
        v[id]=value;
        
        while(ptr<v.size()&&v[ptr]!="")
            temp.push_back(v[ptr++]);
        return temp;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
