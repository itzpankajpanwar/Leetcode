class Solution {
public:
    
    
    
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int, int > hm;
        for(auto &x :arr)
            if(hm[x])
                hm[x]++;
            else
                hm[x]=1;
        vector<int> temp;
        for(auto &x:hm)
            temp.push_back(x.second);
        sort(temp.begin(),temp.end());
        int res =0 , sum=0;;
        for(int i=temp.size()-1;i>=0;i--)
        {
            sum+=temp[i];
            res++;
            if(sum>=arr.size()/2)
                break;
        }
        return res;
        
    }
};