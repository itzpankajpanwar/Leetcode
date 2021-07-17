class Solution {
public:
    
    vector<int> findPeakGrid(vector<vector<int>>& mat)
    {
        int n=mat.size() , m=mat[0].size();
        int i=0 , j=m-1;
        while(i<=j)
        {
            int maxi=-1;
            int mid = i+ (j-i)/2 , index;
            for(int row=0; row<mat.size(); row++)
                    index = mat[row][mid] >= mat[index][mid]? row : index;   

            bool lg = mid-1 >= i && mat[index][mid]<mat[index][mid-1];
            bool rg = mid+1 <= j && mat[index][mid]<mat[index][mid+1];

            if(!lg && !rg)
                return vector<int>({index,mid});
            else if(rg)
                i =mid+1;
            else 
                j=mid-1;
        }
        return vector<int>{-1,-1};
    }
};