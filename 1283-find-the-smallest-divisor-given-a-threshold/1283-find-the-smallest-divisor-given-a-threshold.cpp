class Solution {
public:
    bool func(vector<int>& nums, int threshold, int curr){
        int sum = 0;
        for(int i : nums)
            sum += ceil((double)i / curr);
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = (low + high) / 2;
            if(func(nums, threshold, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};