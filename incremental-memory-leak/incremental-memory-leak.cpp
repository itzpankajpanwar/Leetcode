class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
int i=1;
        while(1){
            if(m1 >= m2){
                if(m1 >= i)
                    m1-=i;
                else
                    return {i,m1,m2};
            }else{
                if(m2 >=i)
                    m2-=i;
                else
                    return {i,m1,m2};
            }
            i++;
        }
    }
};