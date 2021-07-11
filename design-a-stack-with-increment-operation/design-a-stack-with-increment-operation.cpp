class CustomStack {
public:
    vector<int> res;
    int m;
    CustomStack(int maxSize) {
        m = maxSize;
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL);
    }
    
    void push(int x) 
    {
        if(res.size()<m)
        res.push_back(x);
    }
    
    int pop() 
    {
        if(res.size()==0)
            return -1;
        int t=res[res.size()-1]; 
        res.pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        
        int t = k<=res.size() ? k: res.size() ;
        for( int s=0; s<t; s++)
            res[s]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */