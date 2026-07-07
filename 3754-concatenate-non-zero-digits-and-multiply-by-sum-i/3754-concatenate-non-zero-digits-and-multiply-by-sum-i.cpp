class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long x = 0;
        int pos = 1;
        while(n > 0){
            int y = n % 10;
            sum += y;
            x += pos * y;
            if(y != 0) pos *= 10;
            n = n / 10;
        }
        return x * sum;
    }
};