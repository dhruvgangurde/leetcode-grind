class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long s1 = 0, s2 = 0;
        for (int x : nums) {
            s1 += x;
        }
        s2 = (long long)n * (n + 1) / 2;
        int x = 0; // duplicate
        int y = 0; // missing
        long long val1 = s2 - s1;
        long long sq1 = 0, sq2 = 0;
        for (int x : nums) {
            sq1 += (long long)x * (long long)x;
        }
        sq2 = (long long)n * ((long long)n + 1) * (2 * (long long)n + 1) / 6;
        long long val2 = (sq2 - sq1) / val1;
        x = (val2 - val1) / 2; 
        y = (val1 + val2) / 2; 
        return {x, y};
    }
};