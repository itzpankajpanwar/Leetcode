class Solution {
public:
    
    int t=0,ws=0,sum=0;
    
    int solver(string &s,int i, unordered_map<string,int> mp)
    {   
        if(i+sum>s.length())
            return -1;
        for(int p=0;p<ws;p++)
        {
            string temp = s.substr( i+t*p, t);
            if(mp.find(temp)!= mp.end() && mp[temp]!=1 )
                { mp[temp]++;  }
            else
                return -1;       
        }
        return i;
    }
 
    vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string,int> mp;
    t=words[0].length();
    ws=words.size();  
    vector<int> res;    
    for(auto &x:words)
        {   
            if(mp.find(x) != mp.end())
                mp[x]--;
            else
                mp[x]=0;
            sum+=t;
        }

    int ll = s.length(); 
    for(int i=0;i<ll-sum+1;i++)
        {  
            int gg = solver(s,i,mp); 
            if(gg != -1)
                 res.push_back(gg);       
        }
    return res;
    }
};