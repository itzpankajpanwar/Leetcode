class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) 
    {
        string l , u;
        vector<bool> res;
       
        
        for(auto &x: queries)
        {   
           int i=0 , j=0;
           while(i<pattern.size() && j<x.size())
           {
               if(pattern[i] == x[j]) { i++; j++; }
               else 
               { 
                   if(isupper(x[j])) j=x.size();
                   else j++;      
               }
           }
            
           while(j<x.size())
               if(isupper(x[j++]))
               { i=0; break;}
            
           // cout<<i<<"   "<<j<<endl;
            
            if(i>=pattern.size())
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};