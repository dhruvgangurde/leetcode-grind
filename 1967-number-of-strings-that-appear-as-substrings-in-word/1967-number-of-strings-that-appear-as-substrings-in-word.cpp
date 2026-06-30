class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        map<char, int> freq;
        for(auto ch: word){
            freq[ch]++;
        }
        static const size_t npos = -1;
        int count = 0;
        for(auto s: patterns){
            if(word.find(s) != npos){
                count++;
            }
        }
        return count;

    }
};