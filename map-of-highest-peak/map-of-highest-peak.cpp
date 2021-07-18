class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        queue<pair<int,int>> q;
        for(int i=0;i<w.size();i++)
            for(int j=0;j < w[0].size();j++)
            {   if(w[i][j]==1) 
                {   q.push({i,j}); w[i][j]=0 ;}
                else
                    w[i][j]=-1;
            }
            
        
        int ct=1;
        while(!q.empty())
        {
            int s= q.size();
            while(s--)
            {
                auto x = q.front();
                int i = x.first , j = x.second;
                q.pop();
                //w[i][j]=ct;
                if( i-1 >= 0 && w[i-1][j]==-1){ w[i-1][j]=ct; q.push({i-1,j});}
                if( j-1 >= 0 && w[i][j-1]==-1){ w[i][j-1]=ct; q.push({i,j-1});}
                if( i+1  < w.size() && w[i+1][j]==-1) { w[i+1][j]=ct;q.push({i+1,j});}
                if( j+1 < w[0].size() && w[i][j+1]==-1) { w[i][j+1]=ct;q.push({i,j+1});}  
            }
                ct++;
           
        }
        return w;
    }
};