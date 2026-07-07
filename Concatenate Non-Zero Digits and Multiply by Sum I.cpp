class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        int digit = log10(n);
        int divisor = pow(10, digit);
        long long newnum = 0, sum = 0;
        while(divisor > 0){
            int rem = n/divisor;
            if(rem){
                newnum = newnum * 10 + rem;
                sum += rem;
            }
            n = n%divisor;
            divisor /= 10;
        }
        return newnum * sum;
    }
};