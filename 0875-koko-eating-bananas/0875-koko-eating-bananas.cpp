class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int hourly){
        long long totalhours = 0;
        //calculate total hours required if koko eats 'hourly' bananas every hour
        for(int bananas : piles){
            totalhours += ceil((double)bananas / hourly);
        }
        //check if koko can finish within h hours
        return totalhours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //find the maximum pile
        int maxi = INT_MIN;
        for(int bananas : piles)
            maxi = max(bananas, maxi);
        //minimum possible speed = 1
        //maximum possible speed = largest pile
        int low = 1, high = maxi;
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(piles, h, mid)){
                //mid is a possible answer
                //try to minimize the eating speed
                ans = mid;
                high = mid - 1;
            }else{
                //mid is too slow
                //increase the eating speed
                low = mid + 1;
            }
        }
        //minimum eating speed required
        return ans;
    }
};