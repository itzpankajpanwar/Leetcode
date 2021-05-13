class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
    
    vector<int> cb{1,2,3,4,5,6,7,8,9};
    vector<int> temp;
    solveit(cb,temp,k,n,0);
  
    return res;
    }
    
    void solveit(vector<int> &cb,vector<int> &temp,int k,int n,int i)
    {   
        if(n==0 && k==0)
        {
            res.push_back(temp);
            return;
        }
        if(k<=0 || n<0 || i>=9)
            return;
        
        for(int x=i;x<cb.size();x++)
        {
            temp.push_back(cb[x]);
            solveit(cb,temp,k-1,n-cb[x],x+1);
            temp.pop_back();
        }
        return;
    }
};