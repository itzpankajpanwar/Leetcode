class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector<int> res; 
       
        vector<vector<int>> adj(n);
       
        vector<int> indegree(n, 0);
        for( auto x : pre)
        {   
            adj[ x[1] ].push_back( x[0] );
            indegree[ x[0] ]++;
        }
        
        queue<int> q; 
        for( int i=0; i<indegree.size(); i++ )
            if( indegree[i] == 0 )
                q.push(i);
        
        if(q.size() == 0) 
            return res; 
        
        while( !q.empty() )
        {
            int s = q.size(); 
            while(s--)
            {
                auto s = q.front(); 
                q.pop(); 
                res.push_back(s); 
                
                for(auto x : adj[s])
                {   indegree[x]--; 
                    if( indegree[x] == 0) 
                        q.push(x);
                }
            }
        }
        
        if(res.size() != n )
            return {};
        
        return res; 
    }
};