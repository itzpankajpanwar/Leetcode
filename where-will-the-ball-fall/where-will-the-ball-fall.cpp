class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
       
        int n = grid.size() , m = grid[0].size(); 
         vector<int> res(m,-1);
        for(int j =0 ; j< m ; j++ )
        {   
            int t=j;
            //cout<<endl<<j;
            for(int i=0;i<n;i++)
            {   
                //cout<<"\n"<<i<<"   "<<t; 
                if(i==n-1) 
                {   
                     if(grid[i][t]==1 && t+1 < m && grid[i][t+1]==1) {  res[j] = t+1; }
                     else if(grid[i][t]==-1 && t-1 >=0 && grid[i][t-1]==-1) {  res[j]= t-1; }
                     else break;
                }
                else if(grid[i][t]==1 && t+1 < m && grid[i][t+1]==1) t++;
                else if(grid[i][t]==-1 && t-1 >=0 && grid[i][t-1]==-1) t--;
                else break;     
            }
        }
    return res;
    }
};