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
        for(int i = 0; i < nums.size(); i++){
            nums[i] = sumEm(nums[i]);
        }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};