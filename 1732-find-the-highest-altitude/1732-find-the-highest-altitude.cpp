class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude(gain.size()+1);
        altitude[0]=0;
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < gain.size(); i++){
            sum += gain[i];
            altitude[i + 1] = sum;
            maxi = max(max(sum , 0) , maxi);
        }
       
        return maxi;
    }
};