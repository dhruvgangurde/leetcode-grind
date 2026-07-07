class Solution {
public:
    pair<int, int> findMax(const vector<int> &nums){
        int index = 0;
        int maxi = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                index = i;
            }
        }
        return {index, maxi};
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // for each row , we find the find max element in that as it has the most chance of being the peak element
        // if we dont find a peak element, then move in the direction of where the bigger element is present wrt our max element -- elimination
        int n = mat.size();
        int low = 0, high = mat.size() - 1;// for keeping track of row on which we are
        while(low <= high) {
            int mid = low + (high - low) / 2;// middle row
            auto [maybePeak, value] = findMax(mat[mid]);
            int up, down;
            // for checking down
            if(mid + 1 < n){
                down = mat[mid + 1][maybePeak]; 
            }else{
                down = -1;
            }
            // for checking up
            if(mid - 1 >= 0){
                up = mat[mid - 1][maybePeak];
            }else{
                up = -1;
            }
            if(up < value && down < value)
                return {mid, maybePeak};
            if(up > value)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};