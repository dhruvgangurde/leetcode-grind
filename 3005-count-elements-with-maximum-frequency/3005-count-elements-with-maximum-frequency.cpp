class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
        int maxi=0;
        for(auto x:freq){
            int y=x.second;
            maxi=max(maxi,y);
        }
        int count=0;
        for(auto it :freq){
            if(it.second==maxi)count+=it.second;
        }
        return count;
    }
};