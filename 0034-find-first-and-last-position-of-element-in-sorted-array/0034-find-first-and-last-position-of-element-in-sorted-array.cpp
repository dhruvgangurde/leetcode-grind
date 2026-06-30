class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int lowerB = n;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] >= target){
                lowerB = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        }
        low = 0, high = n - 1;
        int upperB = n;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] > target){
                upperB = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        }
        if (lowerB == n || nums[lowerB] != target)
            return {-1, -1};

        return {lowerB, upperB - 1};
    }
};