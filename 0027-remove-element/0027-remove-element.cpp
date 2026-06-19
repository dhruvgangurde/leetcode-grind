class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)return 0;
        int left=0;
        int right=nums.size()-1;
        int count=0;
        while(left<=right){
            while(left<=right && nums[left]!=val)left++;
            while(left<=right && nums[right]==val)right--;
            if(left<right)
            swap(nums[left++],nums[right--]);

            
        }
        return left;
    }
};