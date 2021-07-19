class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int minutes) {
        int profit=0 ;
        for(int i=0 ; i < c.size() ; i++)
            profit += g[i]==0 ? c[i] : 0;
       // cout<<"profit = "<<profit<<endl;
        int np = 0,i,j;
        for(i=0 , j=0;j<minutes;j++)
            np += (g[j]==1 ? c[j] : 0);
       // cout<<"np = "<<np<<endl;
        int ci=np;
        for( ; j<c.size() ; j++,i++)
        {
            int tp = g[j]==1 ? c[j] : 0;
            int gp = g[i]==1 ? c[i] : 0;
            ci = ci+tp-gp;
            np = max(np , ci);
            //cout<<"np = "<<np<<endl;
        }
        
        return profit+np;  
    }
};