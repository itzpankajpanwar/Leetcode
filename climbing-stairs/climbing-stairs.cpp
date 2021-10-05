class Solution {
public:
    int climbStairs(int n) {
    if(n<=3)
        return n;
    int a=1,b=2,temp;
    n-=3;
    while(n--)
        { 
            temp=b+a;
            a=b;
            b=temp;
        }
    return a+b;
    }
};