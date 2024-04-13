class Solution {
public:
    int climbStairs(int n) {
        int sum=0;
        int first=1, second=1;
    if(n<=1)
    return 1;
    for(int i=2; i<=n; i++)
    {

        
        sum=first+second;
        first=second;
        second=sum;
    }
    return sum;
    }
};