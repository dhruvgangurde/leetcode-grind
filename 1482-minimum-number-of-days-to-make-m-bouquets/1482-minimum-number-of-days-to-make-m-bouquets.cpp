class Solution {
public:
    bool canBeUsed(vector<int>& bloomDay, int curr, int m, int k){
        int count = 0;
        int noofB = 0;
        //count consecutive flowers bloomed by 'curr' day
        for(int i : bloomDay){
            if(curr >= i){
                count++;
            }else{
                //make as many bouquets as possible from the current streak
                noofB += count / k;
                count = 0;
            }
        }
        //check the last consecutive streak
        noofB += count / k;
        //check if at least m bouquets can be made
        return noofB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //not enough flowers to make m bouquets
        if((long long)m * k > bloomDay.size())
            return -1;
        //find the minimum and maximum bloom day
        int maxi = 0;
        int mini = INT_MAX;
        for(int i : bloomDay){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        //search space = [minimum bloom day, maximum bloom day]
        int low = mini, high = maxi;
        while(low <= high){
            int mid = (low + high) / 2;
            if(canBeUsed(bloomDay, mid, m, k)){
                //mid is a possible answer
                //try to find a smaller day
                high = mid - 1;
            }else{
                //need more days for enough flowers to bloom
                low = mid + 1;
            }
        }
        //low points to the minimum day required
        return low;
    }
};