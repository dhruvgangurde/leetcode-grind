class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long x = 0;
        int pos = 0;
        while(n > 0){
            int y = n % 10;
            sum += y;
            x += pow(10,pos) * y;
            if(y != 0) pos++;
            n = n / 10;
        }
        return x * sum;
    }
};