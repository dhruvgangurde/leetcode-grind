class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        bool wordfound = false;
        int length=0;
        for(int i = n - 1; i >= 0; i--){
            if(wordfound == false && s[i]==' '){
                continue;
            }else if(wordfound == false){
                wordfound=true;
                length++;
            }else if(s[i] == ' '){
                break;
            }else{
                length++;
            }
        }
        return length;
    }
};