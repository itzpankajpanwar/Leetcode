class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res; 
        
        vector<int> temp;
        int len = l.size() ; 
        for(int i=0 ; i<len ; i++)
        {   bool gg=true;
            temp.clear(); 
            for(int j = l[i]; j <= r[i] ; j++)
                temp.push_back(nums[j]);
            sort(temp.begin() , temp.end());
            int d = temp[1]-temp[0];
            for(int i=2; i<temp.size(); i++)
            {
                if(temp[i]-temp[i-1] != d)  
                { 
                    gg=false; 
                    break;
                }
            }
            res.push_back(gg);
        }
     return res;   
    }
};