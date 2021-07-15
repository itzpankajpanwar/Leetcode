class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> pp(26,0);
        for(auto &x: str)
            pp[x-'a']++;
        string res;
        
        for(auto &x:order)
        {   int i=x-'a';
            while(pp[i]--)
                res += 'a'+i;
        }
        
        for(int i=0;i<26;i++)
            if(pp[i]>0)
                while(pp[i]--)
                res += 'a'+i;
                
        return res;
    }
};