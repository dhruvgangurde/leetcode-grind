class Solution {
public:
    bool isUsable(vector<int>& weights, int days, int curr){
        int dayNeeded = 1;
        int maxWeight = curr;
        for(int i : weights) {
            if(maxWeight < i) {
                dayNeeded++;
                maxWeight = curr;
            }
            maxWeight -= i;
        }
        return dayNeeded <= days;
    } 
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        long long high = 0;
        for (int num : weights) {
            high += num;
        }
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isUsable(weights, days, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};