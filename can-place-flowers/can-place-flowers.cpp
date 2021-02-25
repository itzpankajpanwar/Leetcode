class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl,int n) {
     if(n==0)
         return true;
    if(fl.size()==1 && fl[0]==0 && n==1)
        return true ;
        
    for(int i=0;i<fl.size();i++)
    {   
        if(fl[i]==1) continue;
        if(n==0) return true;
        if(i==0 && fl[i]==0 &&  i+1 < fl.size() && fl[i+1]==0 )
        {
            fl[i]=1;
            n--;
            continue;
        }
        if(i==fl.size()-1 && i>0 && fl[i-1]==0)
        {
            fl[i]=1;
            n--;
            continue;
        }
        if(i!=0 && i!=fl.size()-1 && fl[i-1]==0 && fl[i+1]==0)
        {
            fl[i]=1;
            n--;
            continue;
        }        
    }
    
       return n==0 ? true : false ;
        
    }
};