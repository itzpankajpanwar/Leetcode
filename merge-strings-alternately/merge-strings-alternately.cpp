class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    int i=0,j=0,n=word1.size(),m=word2.size();
    string res="";
    while(i<n && j<m)
         res = res + word1[i++] + word2[j++];
     while(i<word1.size())
         res+=word1[i++];
     while(j<word2.size())
         res+=word2[j++];
    return res;

        
    
    }
};