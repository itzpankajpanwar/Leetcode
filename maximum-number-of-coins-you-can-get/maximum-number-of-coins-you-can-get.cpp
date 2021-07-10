class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin() , piles.end());
        int sum=0;
        int i=0 , j=piles.size()-1;
        while(i<j)
        {
            sum+=piles[j-1];
            j-=2;
            i++;
        }
        return sum;
    }
};

/*

we have to get maximum sum of  2nd selected piles 
greedy solution will work 


*/