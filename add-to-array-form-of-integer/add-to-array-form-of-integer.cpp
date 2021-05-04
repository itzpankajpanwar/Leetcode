class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
    
    reverse(num.begin(),num.end());
        
    int nc=0,oc=0,i=0;
    while(k>0 || nc==1)
    {   
        int n=k%10;
        if(i>=num.size())
            {     
            nc=(n+oc)/10;
            num.push_back( (n+oc)%10 );
            oc=nc;
                
            }
        else
            {
                nc=(num[i]+n+oc)/10;
                num[i]=(num[i]+n+oc)%10;
                oc=nc;  
            }    
        i++;
        k/=10;
    }
    reverse(num.begin(),num.end());
    return num;
    }
};