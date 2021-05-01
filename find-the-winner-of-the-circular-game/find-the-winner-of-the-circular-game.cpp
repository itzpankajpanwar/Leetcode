class Solution {
public:
    int findTheWinner(int n, int k) {
    vector<int> vct;
        
    for(int i=0;i<n;i++)
        vct.push_back(1);
        
    int rem=n-1,pos=0; 
        
    while(rem>0)
    {   
        
       for(int tt=0;tt<k-1;pos++)
            {   
               pos%=n;
               if(vct[pos]==1)
                   tt++;
            }
        
       pos%=n;
        while(vct[pos]!=1)
            {
                pos++; pos%=n;
            }
       vct[pos]=0;
      
       
        rem--; 
        
         pos++;
        pos%=n;
        while(vct[pos]!=1)
            {
                pos++; pos%=n;
            }
  
    }
        
      for(int i=0;i<n;i++)
          {
              if(vct[i] == 1)
                  return i+1;
          }
        
    return 1;
    }
};