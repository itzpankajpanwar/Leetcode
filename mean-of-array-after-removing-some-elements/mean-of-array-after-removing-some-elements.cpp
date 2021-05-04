class Solution {
public:
    double trimMean(vector<int>& arr) {
    int fp=arr.size()*0.05;
    int sum=0,tt=0;
    sort(arr.begin(),arr.end());
    for(int i=fp;i<arr.size()-fp;i++,tt++)
        sum+=arr[i];
    
    double avg=(double)sum/(double)tt;
    
    avg= ceil(avg*100000)/100000;
    
    return avg;
    }
};