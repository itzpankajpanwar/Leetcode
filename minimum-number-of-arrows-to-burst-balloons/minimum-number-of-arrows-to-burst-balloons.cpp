class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end(),[](vector<int> &v1, vector<int> &v2){
            return v1[0]==v2[0] ? v1[1]<v2[1] : v1[0]<v2[0];
        });
        for(auto &x:points)
            cout<<x[0]<<"   "<<x[1]<<endl;
        int cmax=points[0][1] ,res=1;
        for(int i=1 ; i<points.size() ; i++)
        {
            if(points[i][0]>cmax ) { res++; cmax=points[i][1]; };
                
            cmax = min(cmax , points[i][1]); 
        }
        
            
        return res;
        
    }
};