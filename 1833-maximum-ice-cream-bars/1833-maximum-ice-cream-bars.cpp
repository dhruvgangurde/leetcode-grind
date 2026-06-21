class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int LARGEST_INT = 100000;
        vector<int> freq(LARGEST_INT + 1, 0);
        for(auto a : costs){
            freq[(a)]++;
        }
        int maxi = 0;
        for(int price = 1; price <= LARGEST_INT; price++){
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