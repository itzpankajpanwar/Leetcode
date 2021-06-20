class Solution {
public:
    vector<int> ufd;
    
    int dis_joint_set_find( int x)
    {
        return ufd[x] == -1 ? x : dis_joint_set_find(ufd[x]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {   
        int n = edges.size();
        ufd.resize( n+1 , -1);
        for( auto &x: edges)
        {
            int a = dis_joint_set_find(x[0]);
            int b = dis_joint_set_find(x[1]);
            
            if( a == b)
                return x;
            else
                ufd[ dis_joint_set_find(x[0]) ] =  x[1];
        }
        cout<<"heer";
        return edges[0];
    }
};