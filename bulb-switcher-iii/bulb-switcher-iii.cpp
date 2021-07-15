class Solution {
public:
    int numTimesAllBlue(vector<int>& light)
    {
        int maxi = -1,res=0;
        for(int i=0 ; i<light.size() ; i++)
        {
            maxi = max( maxi , light[i]);
            if(maxi == i+1)
                res++;
        }
        return res;
    }
};