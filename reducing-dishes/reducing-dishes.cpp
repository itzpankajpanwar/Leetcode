class Solution {
public:

    int maxSatisfaction(vector<int>& s)
    {   
        int index = -1 ,  profit =0 ; 
        sort( s.begin() , s.end() );
        for(int i =0 ; i< s.size() ; i++)
        {
            if( s[i]<0 ) { } 
            else { index=i--; break; } 
        }
        
        int ci=1 , sum=0 ; 
        if(s[s.size()-1] > 0 )
        for(int i =index+1 ; i< s.size(); i++)
        { 
            profit += s[i]*(ci++); 
            sum += s[i]; 
        }
        
        for(int i=index ; i>=0 ; i--)
        {
            if( profit+sum+s[i] > profit )
            {
                profit = profit+sum+s[i]; 
                sum += s[i]; 
            }
            else break;
        }
        return profit; 

    }
};


/*
for each dish time taken to cook is 1 unit 
profit earned = position in dish order * its weight  

i can take all positive values for sure and taking negative is not sure 

first thing is sort dishes based on weight 
get positive profit 
for each negative profit if adding a negative value increses profit then keep on increaing that muc amount of profit 
if not then return result 

that's it 

*/