class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int res=0;
    for(int i=1;i<arr.size(); i++)
            arr[i]+=arr[i-1];
    for(int i=k-1;i<arr.size();i++)
    {
        int sum = arr[i];
        if(i-k>=0) sum-=arr[i-k];
        if( sum/k >= threshold )
            res++;
    }
     return res;  
    }
};