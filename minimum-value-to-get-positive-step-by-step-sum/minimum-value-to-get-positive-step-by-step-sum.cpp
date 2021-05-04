class Solution {
public:
    int minStartValue(vector<int>& nums) {
    int min_sum=0,sum=0;
    for(auto &x:nums)
    {
        sum+=x;
        if(sum<1 && sum<min_sum)
            min_sum=sum;
    }
    return abs(min_sum)+1;
        
    }
};