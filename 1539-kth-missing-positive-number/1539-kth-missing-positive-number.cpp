class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing(arr.size(),0); 
        for (int i = 0; i < arr.size(); i++) {
            missing[i] = arr[i] - (i + 1);
        }
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(missing[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high + 1 + k;
    }
};