class Solution {
public:
    int findLUSlength(string a, string b) {
    if(a.length()==0 || b.length()==0)
        return -1;
    if( a!= b)
        return max(a.length(),b.length());
    if(a==b)
        return -1;
    return max(findLUSlength(a.substr(0,a.length()-1),b) , (findLUSlength(a,b.substr(0,b.length()-1))) );
    } 
};