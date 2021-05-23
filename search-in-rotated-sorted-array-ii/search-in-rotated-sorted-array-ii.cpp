class Solution {
public:
    bool search(vector<int>& nums, int target) {
    
      int s=0,e=nums.size()-1;
      
        while(s<=e)
        {   
            cout<<"\n s= "<<s<<"\t e= "<<e;
            int mid = s+ (e-s+1)/2;
            cout<<"\tmid = "<<nums[mid];
         
            if(nums[mid] == target)
                return true;
            else if( nums[s]==target or nums[e]==target)
                    return true;
            else if(nums[s] == nums[mid] or  nums[mid]==nums[e])
            {
                s++;
                e--;
            }
            
            else if(target>nums[mid])
            {   
                if(nums[s]<nums[mid])
                    s=mid+1;
                else
                {   
                   
                    if(target>= nums[s]) e = mid-1;
                    else   s=mid+1; 
                }
            }
            else if(target<nums[mid])
            {   
                if(target<nums[s] && nums[s]<nums[mid])
                    s=mid+1;
                else if(nums[s]<nums[mid])
                    e=mid-1;
                else
                {
                    if(target>= nums[s]) s=mid+1;
                    else e=mid-1;
                }
            }   
        }
    return false;
    }
};