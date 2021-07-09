class Solution {
public:
   // Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0, m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] += A[i][j - 1];

        unordered_map<int, int> counter;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter = {{0,1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};

/*

some sort of prefix sum ideas 

or all possibl matrix with current index  ? 

worst case : matrix is 100*100
bruteforce wont work ( n^3 solution works ) 100^3 = 10^6


PREFIX SUM 

intitial      row sum      col sum 

0 1 0          0 1 1        0 1 1
1 1 1  ----->  1 2 3 -----> 1 3 4
0 1 0          0 1 1        1 4 5

get a submatrix sum and check if equal 
if equal then gg else move next 


                            
    



*/
