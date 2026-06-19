class Solution {
public:
    int sumEm(int num){
        int ans = 0;
        while(num > 0){
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            nums[i] = sumEm(nums[i]);
            mini = min(nums[i], mini);
        }
        return mini;
    }
};