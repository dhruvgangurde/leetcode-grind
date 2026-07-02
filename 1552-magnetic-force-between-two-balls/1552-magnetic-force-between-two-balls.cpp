class Solution {
public:
    bool canBeplaced(vector<int> &nums, int cows, int dist) {
        int count = 1;
        int last = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] - last >= dist) {
                count++;
                last = nums[i];
            }
        }
        return count >= cows;
    }
    int aggressiveCows(vector<int> &nums, int cows) {
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN, mini = INT_MAX;
        for(auto i : nums){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        int low = 1, high = maxi - mini;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(canBeplaced(nums, cows, mid)){
                low = mid + 1;
                continue;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans = aggressiveCows(position,m);
        return ans;
    }
};