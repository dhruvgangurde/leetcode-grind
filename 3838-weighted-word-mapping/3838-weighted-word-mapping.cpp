class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for(string s : words){
            int sum = 0;
            for (char c : s) {
                int alphabet = c - 'a';
                sum += weights[alphabet];
            }
            result += char('z' - sum % 26);
        }
        return result;
    }
};      