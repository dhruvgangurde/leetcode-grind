class Solution {
public:
    int mySqrt(int num) {
        int ans;
        int low = 0, high = num;
        while(low <= high){
            long long mid = (low + high) / 2;
            long long square = mid * mid;
            if(square == num)
                return mid;
            else if(square > num)
                high = mid - 1;
            else{
                low = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};