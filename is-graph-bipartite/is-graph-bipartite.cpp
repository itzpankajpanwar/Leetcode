class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int start = 0; start < n; ++start)
        {
            if (color[start] == -1) 
            {
                stack<int> stk;
                stk.push(start);
                color[start] = 0;

                while (!stk.empty()) 
                {
                    int node = stk.top();
                    stk.pop();

                    for (int neigh : graph[node]) 
                    {
                        if (color[neigh] == -1) 
                        {
                            stk.push(neigh);
                            color[neigh] = color[node] ^ 1;
                        } 
                        else if (color[neigh] == color[node]) 
                            return false;
                    }
                }
            }
        }
        return true;
    }
};


/*

2 colorability question ? 

*/