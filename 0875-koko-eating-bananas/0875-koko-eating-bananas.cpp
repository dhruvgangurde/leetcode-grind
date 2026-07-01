class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int hourly){
        long long totalhours = 0;
        for(int i : piles){
            totalhours += ceil((double)i / hourly);
        }
        return totalhours <= h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i : piles)
            maxi = max(i, maxi);
        int low = 1, high = maxi;
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(piles, h, mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};