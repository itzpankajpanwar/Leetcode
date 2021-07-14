class Solution {
public:
    vector<string> letterCasePermutation(string s) 
    {
        queue<string> q;
        unordered_set<string> visi;
        q.push(s);
        unordered_set<string> res  = {s};
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto x = q.front();
                q.pop();
                if(visi.find(x) == visi.end())
                {   
                        visi.insert(x);
                        for(int i=0 ; i<x.length() ; i++)
                        {
                            if( x[i]>='a' && x[i]<='z')
                            {
                                string temp =x;
                                temp[i] = 'A'+ (x[i]-'a');
                                if(visi.find(temp) == visi.end())
                                    { res.insert(temp); q.push(temp);}
                            }
                            else if( x[i]>='A' && x[i]<='Z')
                            {
                                string temp =x;
                                temp[i] = 'a'+ (x[i]-'A');
                                if(visi.find(temp) == visi.end())
                                    { res.insert(temp); q.push(temp);}
                            }
                        }
                    }      
               }
        }
        vector<string> gg;
        for(auto &x: res)
            gg.push_back(x);
        return gg; 
    }
};