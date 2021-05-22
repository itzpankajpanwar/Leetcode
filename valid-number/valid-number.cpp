class Solution {
public:
    
    bool isNumber(string s) {
        bool sign,dot,digit,contain_digit,ef;
        sign = dot = digit = contain_digit = ef =  false;
     
        for( int i=0 ; i<s.length();i++)
        {   
            char x = s[i];
            if( x=='e' or x=='E')
            {
                if(!digit or ef) return false;
                else if(i+1>=s.length()) 
                    return false;
                else if( (s[i+1]=='+' or s[i+1]=='-') && (i+2 < s.length()) && (s[i+2]>='0' && s[i+2]<='9')  )
                     {  ef = true; }
                else if(  (s[i+1]=='+' or s[i+1]=='-') ) 
                    return false; 
                else if( !( (s[i+1]>='0' && s[i+1]<='9') ))
                    return false;
                else ef= true;       
            }
            else if( (x>='a' && x<='z') or (x>='A' && x<='Z'))
                return false;
            else if(x=='.')
            {      
                if( dot or ef ) return false;
                if(!digit)
                {
                    if(i+1>=s.length()) return false;
                    if(s[i+1]=='e' or s[i+1]=='E')
                        return false;
                    dot = true;
                    
                }
                else dot=true;
            }
            else if(x=='+' or x=='-')
            {   
                if(ef && (s[i-1]=='e' or s[i-1]=='E'))
                    sign=true;
                else if( sign or dot or digit ) return false;
                else sign = true;
            }
            else if(x>='0' && x<='9')
                digit = true;
        }
        return true;
    }
};