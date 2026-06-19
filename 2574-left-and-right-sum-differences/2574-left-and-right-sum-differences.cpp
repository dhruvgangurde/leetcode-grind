class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i: nums){
            totalSum += i;
        }
        int leftSum = 0;
        for(int i = 0; i < n; i++){
            int rightSum = totalSum - leftSum - nums[i];
            int curr = abs(rightSum - leftSum);
            leftSum += nums[i];
            nums[i] = curr;
        }
        return nums;
    }
};
