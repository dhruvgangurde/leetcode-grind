class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mini = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            // check which half is sorted or not
            if(nums[low] <= nums[mid]){
                //left half is sorted
                //update mini and discard left half
                mini = min(nums[low], mini);
                low = mid + 1;
            }else if(nums[mid] < nums[high]){
                //right half is sorted
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};