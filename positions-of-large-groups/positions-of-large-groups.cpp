class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
    
    vector<vector<int>> res;
    int ct=0;
    int start=0,end=0;
    char pre = '.';
    for(auto &x:s)
        {
            if(x==pre)
              ct++; 
            else
            {
                if(ct>=3)
                {
                    vector<int> temp{start,end-1};
                    res.push_back(temp);
                }
                ct=1;
                start=end;
            }
        end++;
        pre=x;
        }
    if(ct>=3)
    {
        vector<int> temp{start,end-1};
                    res.push_back(temp);
    }
    return res;
    }
};