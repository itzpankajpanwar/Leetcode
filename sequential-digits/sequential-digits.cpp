class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> gg,res;
        for(int i=1;i<=9;i++)
        {
            gg.push_back(i);
            int cd=i;
            for(int j=i+1;j<=9;j++)
            {
                cd = cd*10 + j;
                gg.push_back(cd);
            }
        }
        for(auto &x:gg)
        {
            if(x>=low && x<=high)
                res.push_back(x);
        }
        sort(res.begin(),res.end());
        return res;
    }
};