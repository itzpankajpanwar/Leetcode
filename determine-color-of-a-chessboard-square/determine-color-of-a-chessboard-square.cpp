class Solution {
public:
    bool squareIsWhite(string c) {
        int i=c[0]-'a' , j = c[1]-'0';
        int s;
        cout<<i<<"  "<<j;
        s = i%2==0 ? 1 : 0;
        cout<<"  "<<s;
        if( (j%2) ==0)
        {  s = s == 1 ? 0 : 1; }
        cout<<"  "<<s;
        return s==1 ? false : true ;
            
    
    }
};