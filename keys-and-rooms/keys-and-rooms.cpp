class Solution {
public:
     void dfs(vector<vector<int>>& rooms , int i , vector<bool> &dp)
     {  if(dp[i] == true) return ;
        dp[i] = true ;
        for( auto&x: rooms[i]) dfs(rooms , x , dp);
     }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    
        int n =rooms.size();
        vector<bool> dp(n , false);
        
        dfs( rooms , 0 , dp);
       
        for(int i=0 ; i<dp.size() ; i++)
            if( dp[i] == false)
                return false;
        return true;

    }
};