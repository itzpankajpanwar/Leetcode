class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        vector<int> ct(26,0),tt;
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            ct[s[i]-'a']++;
            if(i>0) 
                ct[s[i-1]-'a']--;
            tt = ct;
            for(int j=i+1 ; j<n; j++)
            {
                tt[s[j]-'a']++;
                int mini=501 , maxi=0;
                for(auto &x:tt)
                {
                    if(x>0) 
                        mini = min(mini,x);
                    
                    maxi = max(maxi,x);
                }
                //cout<<i<<"   "<<j<<"   maxi "<<maxi<<"   "<<mini<<endl;
                res += maxi-mini > 0 ? maxi-mini : 0;
            }
        }
        return res;  
    }
};