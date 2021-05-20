class Solution {
public:
    int myAtoi(string s) {
    int sign=1;
    size_t res=0;
    size_t maxi = pow(2,31);
    cout<<maxi;
    int f=0;
    int mf=0,df=0;
    for(auto &x:s)
    {    
        
        if((mf==1 or df==1) && !(x>='0' && x<='9') )
           break;
        if(x=='.')
            break;
        if(x=='-') {sign=0; mf=1;}
        if(x=='+') mf=1;
        else if( x>='0' && x<='9')
        {   
            df=1;
            res = res*10 + x-'0';
            if(res>=maxi)
                {   res=maxi;
                    if(sign==1)
                        f=1;
                    break; 
                }  
        }
        else if( res==0 && ((x>='a' && x<='z') or (x>='A' && x<='A')) )
            return 0;
        
    }
    return sign==0 ? -res : res-f ;
    }
};