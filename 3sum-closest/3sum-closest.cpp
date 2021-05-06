class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int res=INT_MAX,fr=0;
    for(int i=0;i<nums.size();i++)
    {
        int fp=0;
        int lp=nums.size()-1;
        
        while(fp<lp)
        {
            if(fp==i) { fp++; continue; }
            if(lp==i) { lp--; continue; }
            
            int min=nums[i]+nums[fp]+nums[lp];
            
            if(abs(target-min)<res)
            { res=abs(target-min);
              fr=min;
            }
            
            if(min>target) lp--;
            else if(min<target)fp++;
            else return target;
        }
    }
    return fr;
    }
};