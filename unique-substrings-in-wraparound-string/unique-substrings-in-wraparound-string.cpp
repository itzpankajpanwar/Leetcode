class Solution {
public:
    int findSubstringInWraproundString(string p) {
   
    vector<int> cnt(26,0);
    int n=p.length();
    int mx=1;
    for(int i=0;i<n;i++)
    {
        if(i>0 and (p[i]-p[i-1]==1 or p[i-1]-p[i]==25))
            mx++;
        else
            mx=1;
        cnt[p[i]-'a']=max(cnt[p[i]-'a'],mx);
    }
    int ans=0;
    for(int i=0;i<26;i++)ans+=cnt[i];
    return ans;
    }
};