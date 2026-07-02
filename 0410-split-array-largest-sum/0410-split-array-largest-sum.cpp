class Solution {
public:
    bool f(vector<int>& nums, int k, int curr) {
        int partitions = 1;
        int sum = 0;
        for(int i : nums) {
            if(sum + i > curr){
                partitions++;
                sum = i;
            }else
                sum += i;
        }
        return partitions <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high = 0;
        for(int i : nums) {
            low = max(low, i);
            high += i;
        }
        while(low <= high) {
            int mid = (low + high) / 2;
            if(f(nums, k ,mid)) 
                high = mid - 1;
            else    
                low = mid + 1;
        }
        return low;
    }
};