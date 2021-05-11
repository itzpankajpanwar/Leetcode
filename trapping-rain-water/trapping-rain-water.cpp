class Solution {
public:
    int trap(vector<int>& height) {
    
    int n=height.size();
    if(n==0)
        return 0;
    vector<int> lm(n,0);
    lm[0]=height[0];
    for(int i=1;i<height.size();i++)
        lm[i]=max(lm[i-1],height[i]);
    
    vector<int> rm(n,0);
    rm[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--)
        rm[i]=max(rm[i+1],height[i]);
    
    int res=0;
    for(int i=1;i<n-1;i++)
    {
        int tt=min(lm[i],rm[i])-height[i];
        if(tt>0)
            res+=tt;
    }
      return res; 
    }
};