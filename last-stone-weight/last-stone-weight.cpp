class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    sort(stones.begin(),stones.end());
    
    while(stones.size()>1)
    {   
        int t1=stones[stones.size()-1]-stones[stones.size()-2];
        stones.pop_back();
        stones.pop_back();
        if(t1 != 0 ) 
        {stones.push_back(t1);
        sort(stones.begin(),stones.end());}
    }
        return stones.size()==1 ? stones[0] : 0 ;
    }
};