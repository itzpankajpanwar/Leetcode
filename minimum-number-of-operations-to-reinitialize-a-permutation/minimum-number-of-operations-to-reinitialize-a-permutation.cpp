class Solution {
public:
    void suffle(vector<int> &prem , int n)
    {   
        vector<int> temp;
        temp = prem;
        for(int i=0;i<n;i+=2)
        {   temp[i] = prem[i/2];
            temp[i+1] = prem[(n/2)+(i/2)];
        }
        prem = temp;
    }
    
    bool comp(vector<int> &gg,int &n)
    {
        for(int i=0;i<n;i++)
            if(gg[i]!=i)
                return false;
        return true;
    }
    int reinitializePermutation(int n) 
    {
       vector<int> prem ;
       for(int i=0;i<n;i++)
            prem.push_back(i);
        suffle(prem,n);
        int steps=1;
        while( comp(prem,n) != true )
        {
            suffle(prem,n);
            steps++;
        }
       return steps; 
    }
};