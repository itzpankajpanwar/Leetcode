class Solution {
public:
  
    int removePalindromeSub(string s) {
        if(s=="") return 0;
        return (checkPalin(s)==true)?1:2;
    }
     bool checkPalin(string s){
        string rev=s;
        reverse(s.begin(), s.end());
        return (s==rev)?true:false;
    }
};