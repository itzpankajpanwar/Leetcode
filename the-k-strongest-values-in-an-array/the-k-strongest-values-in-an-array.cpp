class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k)
    {
        sort(arr.begin() , arr.end());
        int n=arr.size()-1;
        int i=0 , j =arr.size()-1;
        vector<int> res;
        int med = arr[n/2];
        while(k--)
        {
            if( j == (n/2) || (abs(arr[i]-med) > abs(arr[j]-med)) )
                  res.push_back(arr[i++]);
            else 
                res.push_back(arr[j--]);      
        }
        return res;
    }
};