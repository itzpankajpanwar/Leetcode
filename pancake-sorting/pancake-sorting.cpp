class Solution {
public:
    vector<int> res;
    vector<int> pancakeSort(vector<int>& arr) {
    for(int i=arr.size()-1;i>0;i--)
        set_max(arr,i);
    return res;   
    }
    
    void set_max(vector<int>& arr , int i)
    {   
        int max=0 , index=0;
        vector<int> new_array;
        
        for(int k=0;k<=i;k++)
            if(arr[k]>max)
             { max=arr[k]; index=k; }
        
        if(index != i)
        {
            for(int x=i;x>index;x--)
                new_array.push_back(arr[x]);
            for(int x=0;x<index;x++)
                new_array.push_back(arr[x]);
            arr = new_array;

            res.push_back(index+1);
            res.push_back(i+1);
        }
    
    }
};