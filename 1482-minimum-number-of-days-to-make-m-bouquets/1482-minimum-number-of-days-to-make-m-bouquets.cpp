class Solution {
public:
    bool canBeUsed(vector<int>& bloomDay, int curr, int m, int k){
        int count = 0;
        int noofB = 0;
        for(int i : bloomDay){
            if(curr >= i){
                count++;
            }else{
                noofB += count / k;
                count = 0;
            }            
        }
        noofB += count / k;
        return noofB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(((long long) m * (long long) k) > bloomDay.size()) 
            return -1;
        int maxi = 0;
        int mini = INT_MAX;
        for(int i : bloomDay){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        int low = mini, high = maxi;
        while(low <= high){
            int mid = (low + high) / 2;
            if(canBeUsed(bloomDay, mid, m, k)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};