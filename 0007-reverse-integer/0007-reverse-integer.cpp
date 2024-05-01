class Solution {
public:
    int reverse(int x) {
    long long reversedNum;
/*Consider the case where the input x is a large number, such as 1534236469. When you reverse this number, you get 9646324351, which exceeds the maximum value representable by a 32-bit signed integer (int). Storing this value in an int would result in integer overflow, leading to undefined behavior.*/
        reversedNum=0;
    if(x>0)
    {while(x>0)
        {
            reversedNum=reversedNum*10+x%10;
            x=x/10;
        }
    }
    else
    {    x=abs(x);
        while(x>0)
        {
            reversedNum=reversedNum*10+x%10;
            x=x/10;
        }
    reversedNum=-1*reversedNum;}

        if (reversedNum > INT_MAX || reversedNum < INT_MIN) {
            return 0; // Return 0 for overflow
        } else {
            return reversedNum;
        }
    }
};