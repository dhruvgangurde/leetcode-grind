class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;
        for(auto cost : costs){
            maxCost = max(maxCost, cost);
        }
        vector<int> freq(maxCost + 1, 0);
        for(auto a : costs){
            freq[(a)]++;
        }
        int maxi = 0;
        for(int price = 1; price <= maxCost; price++){
            if(freq[price] == 0)continue;
            int canBuy = min(freq[price] , coins/price);
            maxi += canBuy;
            coins -= canBuy*price;
            if(price > coins){
                break;
            }
        }
        return maxi;
    }
};