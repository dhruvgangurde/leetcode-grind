class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[low] == nums[high] && nums[low] == nums[mid]){
                low++;
                high--;
                continue;
            }
            //check if LEFT HALF IS SORTED 
            if (nums[low] <= nums[mid]) {
                // if target lies in the sorted left half, search there
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                // else search in the right half
                else {
                    low = mid + 1;
                }
            }else{
                //check right half
                // if target lies in the sorted right half, search there
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                // else search in the left half
                else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};