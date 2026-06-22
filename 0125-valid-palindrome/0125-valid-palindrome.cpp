class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";
        for(char c : s){
            int x = (int) c;
            if( 65 <= x && x <= 90){
                //capital letter
                x += 32;
                newString += (char)x;
            }else if(97 <= x && x <= 122){
                //lowercase letter
                newString += (char)x;
            }else if(48 <= x && x <= 57){
                //(0-9)
                newString += (char)x;
            }else{
                continue;
            }
        }
        int left = 0;
        int right = newString.size() - 1;
        while(left <= right){
            if(newString[left] != newString[right]){
                return false;
            }
            left ++;
            right--;
        }
        return true;
    }
};