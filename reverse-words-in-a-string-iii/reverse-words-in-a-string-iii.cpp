class Solution {
public:
    string reverseWords(string s) {
    string res,temp;
    for(auto &x : s)
    {   
      if( x != ' ')
        temp=x+temp;
      else
      {
          res+=temp+x;
          temp="";
      } 
    }
    if(temp.length() != 0)
        res+=temp;
    return res;
        
    }
};