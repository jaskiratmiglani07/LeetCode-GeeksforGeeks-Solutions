class Solution {
public:
    int reverse(int x) {
        long long reversedNum;
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
            return static_cast<int>(reversedNum);
        }
    }
};