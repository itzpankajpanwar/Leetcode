class Solution {
public:
    unordered_map< char,pair<int,int> > keyboard;
    int dp[302][6][6][6][6];
    
    int solver(string word , int index  , int p,int q, int x,int y)
    {   
        if(index>=word.length())
            return 0;
        
        int a,b;
       
        if( x!=-1 && dp[index][p][q][x][y] != -1)
           return dp[index][p][q][x][y];
        
            
       else if(x==-1 && y==-1)
            a = solver(word,index+1,p,q,keyboard[word[index]].first,keyboard[word[index]].second); 
        else   
            {   a = abs(x-keyboard[word[index]].first)+abs(y-keyboard[word[index]].second);
                a += solver(word,index+1,p,q,keyboard[word[index]].first,keyboard[word[index]].second);
            }
           
       b = abs(p-keyboard[word[index]].first)+abs(q-keyboard[word[index]].second);
       b+=solver(word,index+1 , keyboard[word[index]].first , keyboard[word[index]].second , x , y);
    
    if(x == -1)
        return min(a,b);
    else 
        return dp[index][p][q][x][y] = min(a,b);
            
    }
    
    int minimumDistance(string word) {
        
        for(int i=0;i<5;i++)   
            for(int j=0;j<6;j++)
            {
                if(i==4 && j==2)
                    break;
                keyboard['A'+(6*i+j)]={i,j};
            }
        
        memset(dp , -1 , sizeof(dp) );
        
        int p = keyboard[word[0]].first;
        int q = keyboard[word[0]].second;
        return solver(word,1,p,q,-1,-1);
    }
};