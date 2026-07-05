class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int count = 1;
        for(int i : arr) 
            missing.push_back(i - count++);
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(missing[mid] >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high + k + 1;
    }
};