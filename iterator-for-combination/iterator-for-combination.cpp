class CombinationIterator {
public:
    vector<string> res;
    int i=0;
    bool x_not_in_gg(char x , string gg)
    {
        for(auto &t:gg)
            if( t >= x)
                return false;
        return true;
    }
    
    void generate_all_combination(string ch , string gg, const int cl)
    {
        if(gg.length() == cl)
        {
            res.push_back(gg);
            return;
        }
        
        for(auto &x:ch)
        {
            if( x_not_in_gg(x,gg))
            {
                string temp = gg+x;
                generate_all_combination(ch,temp,cl);
            }
        }
    }
    CombinationIterator(string ch, int cl) {
        for(auto &x: ch)
        {
            string gg = "";
            gg = gg+x;
            generate_all_combination(ch , gg ,cl);
        }
    }
    
    string next() {
        return res[i++];
    }
    
    bool hasNext() {
        if(i<res.size())
            return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */