class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res=0 , pre = 0 ;
        for(auto &x: target)
        {
            res += x-pre > 0 ? x-pre : 0;
            pre=x;
        }
        return res; 
    }
};


/*
answer should be atleast maximum no 
i have some restrictoins(minimum values )

if i do simulation then time n*(max value) which result in TLE 

i have to find a smarter way to do it 
greedy approach will surely work 

i.e. select continuous positive array and decrements all value by 1 
by complexity wise not a good solution at all 

JUST A SLOP PROBLEM 





*/