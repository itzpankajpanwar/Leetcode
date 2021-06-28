#define vvi vector<vector<int>>
class Solution {
public:
    vvi res ;
    
    void solver( vvi &graph , vector<int> &temp ,int i)
    {
        if( i == graph.size()-1)
        {   
            temp.push_back(i);
            res.push_back(temp);
            temp.pop_back();
            return ; 
        }
        
        temp.push_back(i);
        for(auto &x: graph[i])
            {
                solver(graph , temp , x);
            }
        temp.pop_back();   
    }
    
    vvi allPathsSourceTarget(vvi &graph) 
    {
        int n=graph.size()-1;
        vector<int> temp;
        solver( graph , temp , 0 );
        return res;
    }
};