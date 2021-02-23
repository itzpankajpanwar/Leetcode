class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      
    unordered_map<long int,long int>  mt;
    long int max =INT_MIN;
    for(auto& x: nums)
    {
        mt[x]++;
        if(x>max)
            max=x;
    }
    for(long int i=1;i<=max+1;i++)
        {
            if(!mt.count(i))
                return i;
        }
    return 1;
        
    }
};