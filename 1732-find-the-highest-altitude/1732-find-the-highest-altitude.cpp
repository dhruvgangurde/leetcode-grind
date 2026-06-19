class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude(gain.size()+1);
        altitude[0]=0;
        int sum = 0;
        for(int i = 0; i < gain.size(); i++){
            sum += gain[i];
            altitude[i + 1] = sum;
        }
        int maxi = INT_MIN;
        for(int i : altitude){
            if(i > maxi)maxi = i;
        }
        return maxi;
    }
};