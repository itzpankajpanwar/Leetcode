class NumArray {
public:
    vector<size_t> rsum;
    NumArray(vector<int>& nums) {
        int sum=0;
        for(auto &x:nums)
        {
            sum+=x;
            rsum.push_back(sum);
        }
            
        
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return rsum[right];
        return rsum[right]-rsum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */