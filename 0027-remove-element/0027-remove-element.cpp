class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;//will find the 1st occurence of val in the nums
        int right = nums.size() - 1;//will find the first occurence of non-val in nums
        //after finding right positions for left and right we swap them
        int count = 0;
        while(left <= right){
            while(left <= right && nums[left] != val){
                left++;
            }
            while(left <= right && nums[right] == val){
                right--;
            }
            if(left < right){
                swap(nums[left++],nums[right--]);
            }
        }
        return left;
    }
};