class Solution {
public:
    int countBalls(int l, int h) {
        
    vector<int> vt(60,0);
        
    for(int i=l ; i<= h ;i++)
    {
        int n=0;
        int t=i;
        while(t)
        {
            n+=t%10;
            t/=10;
        }
        vt[n]++;
    }
    int res=0;
    int max = INT_MIN;
    for(int i=0;i<60;i++)
    {
        if(vt[i]>=max)
            max=vt[i];
        
    }
        return max;
    }
};