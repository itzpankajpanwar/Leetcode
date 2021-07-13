class Solution {
public:
    vector<int> res;
    void partition( string &s , int index , int mli )
    {
        if( index >= s.length())
            return ;
        for(int i=index ; i<=mli; i++)
        {
            for(int j=i+1;j<s.length(); j++)
                if( s[j]==s[i])
                    mli = max(mli ,j); 
        }
        res.push_back(mli-index+1);
        partition( s, mli+1 , mli+1);
        
    }
    vector<int> partitionLabels(string s) 
    {
        partition(s , 0 , 0);
        return res ;
    }
};


// greedy works 