class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        map<char, int> freq;
        for(auto ch: word){
            freq[ch]++;
        }
        int count = 0;
        for(auto s: patterns){
            if(word.find(s) != -1){
                count++;
            }
        }
        return count;

    }
};