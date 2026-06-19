class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        int maxi=0;
        while(left<right){
            int volume=(right-left)*min(arr[right],arr[left]);
            maxi=max(volume,maxi);
            if(arr[left]<arr[right])left++;
            else right--;
        }
        
        return maxi;
        
    }
};