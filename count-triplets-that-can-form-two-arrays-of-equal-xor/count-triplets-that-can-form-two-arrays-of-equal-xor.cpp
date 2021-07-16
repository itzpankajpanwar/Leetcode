class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        for(int i=1;i<arr.size();i++)
            arr[i] = arr[i]^arr[i-1];
        
        int res=0;
        for(int i=0;i<arr.size();i++)
            for(int j=i+1;j<arr.size();j++)
                for(int k=j;k<arr.size();k++)
                {   
                    int t = arr[k];
                    if(i>0) t^= arr[i-1];
                    
                    int tj , aj ;
                    aj = t^arr[j-1];
                    
                    tj = t^aj;

                    if(tj == aj)
                    {   
                        //cout<<" t = "<<t<<"   "<<"tj = "<<tj<<"    aj =  "<<aj<<endl; 
                        //cout<<i<<"  "<<j<<"  "<<k<<endl;
                        res++;
                    }
                }
        return res;
    }
};