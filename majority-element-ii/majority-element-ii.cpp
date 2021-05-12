class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    
        
    int n1=-1,n2=-1,c1=0,c2=0;
    for(auto &x:nums)
    {
        if(n1==x) c1++;
        else if(n2==x) c2++;
        else if(c1==0) { c1=1; n1=x; }
        else if(c2==0) { c2=1; n2=x; }
        else { c1--; c2--; }
    }
    //cout<<n1<<"   "<<n2;
    vector<int> res;
    int a=0,b=0;
    for(auto &x:nums)
    {
        if(x==n1) a++;
        else if(x==n2) b++;
    }
    if(a>nums.size()/3)
        res.push_back(n1);
    if(b>nums.size()/3)
        res.push_back(n2);
    return res;  
    }
};