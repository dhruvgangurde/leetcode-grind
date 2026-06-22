class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> check(26, 0);
        for(char c : text){
            check[c - 'a']++;
        }
        int a = check['b' - 'a'];
        int b = check['a' - 'a'];
        int c = check['l' - 'a'] / 2;
        int d = check['o' - 'a'] / 2;
        int e = check['n' - 'a'];
        int result = min({a, b, c, d, e});
        return result;
    }
};