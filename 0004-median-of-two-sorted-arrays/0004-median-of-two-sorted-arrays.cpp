class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int size=m+n;
        vector<int> ans(size);
        int p1=0;
        int p2=0;
        int p3=0;
        while(p1<m && p2<n){
            if(nums1[p1]<nums2[p2]){
                ans[p3]=nums1[p1];
                p1++;
            }else{
                ans[p3]=nums2[p2];
                p2++;
            }
            p3++;
        }
        while(p1<m){
            ans[p3]=nums1[p1];
            p1++;
            p3++;
        }
        while(p2<n){
            ans[p3]=nums2[p2];
            p2++;
            p3++;
        }
        if(size % 2){
            double result = (double) ans[size / 2];
            return result;
        }
        double result = (double)(ans[size/2] + ans[size/2 - 1]) / 2.0;
        return result;
    }
};