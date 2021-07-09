static vector<int> dirs = { 0 , 1 , 0 , -1 , 0 };
class Solution {
public:
    
    int m , n;
    
    int getFlip(int i,int j,int bitVec , int m , int n )       
    {
        int x,y,pos=m*n-1-i*n-j;  
        bitVec^=1<<pos;
        for(int d=0;d<4;d++)
        {
            x=i+dirs[d],y=j+dirs[d+1];
            if(x>=0&&y>=0&&x<m&&y<n)
                pos=m*n-1-x*n-y,bitVec^=1<<pos;          
        }
        return bitVec;
    }
    
    int minFlips(vector<vector<int>>& mat) 
    {   
       int m = mat.size() , n = mat[0].size(); 
        
        int bitvec = 0;
        for(int i=0 ; i< m ;i++)
            for(int j=0 ; j< n ; j++)
            {  bitvec<<=1; bitvec|=mat[i][j]; }
        if(!bitvec)
            return 0;
        queue<int> q;
        unordered_set<int> visi;
        q.push(bitvec);
        
        int distance = 0;
        cout<<m<<"   "<<n;
        while( ! q.empty())
        {
            int s = q.size();
            while(s--)
            {
                if( !q.front() )
                    return distance;
                for(int i=0;i<m;i++)                   
                    for(int j=0;j<n;j++)
                    {
                        bitvec=getFlip(i,j,q.front(),m,n); 
                        if(!visi.count(bitvec))
                            q.push(bitvec),visi.insert(bitvec);
                    }
                q.pop();
            }
            distance++;
        }
    return -1;
    }
};