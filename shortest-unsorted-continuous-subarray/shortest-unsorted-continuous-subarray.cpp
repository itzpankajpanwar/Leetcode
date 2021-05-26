#define l1(i,j,k)  for(int i = j;i<k;i++)
#define l2(i,j)  for(int i=j;i>=0;i--)

class Solution {
public:
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL);}
    int findUnsortedSubarray(vector<int>& n) {
    int nn=n.size() , mini=INT_MAX , maxi = INT_MIN , l = nn-1 , r = 0 , f=0;
    l1(i,1,nn){
                if(n[i]<n[i-1]) f=1;
                if(f) mini =min( mini , n[i]); }
    f=0;
    l2(i,nn-2) { 
                if(n[i]>n[i+1]) f=1;
                if(f) maxi =max( maxi, n[i]); }   
    l1(i,0,nn) if( mini < n[i]) {   l = i; break; }
    l2(i,nn-1) if( maxi > n[i]) {   r = i; break; }
    return r-l > 0 ? r-l+1 : 0;
    }
};