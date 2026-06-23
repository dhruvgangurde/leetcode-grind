class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sp=0,cp=prices[0];
        for(int i=1;i<prices.size();i++){
            sp=max(prices[i]-cp,sp);
            cp=min(prices[i],cp);
        }
        return sp;
    }
};