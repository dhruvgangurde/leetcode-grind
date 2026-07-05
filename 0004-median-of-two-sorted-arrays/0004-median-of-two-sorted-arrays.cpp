/*
TC : O(m + n) -- brute force using merge approach
SC : O(m + n) auxilary space
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
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2; // elements that we need on left for equal partition
        int l = INT_MIN, r = INT_MIN;
        while(low <= high) {
            int mid1 = (low + high) / 2;// taking mid1 element from nums1 on left of the partition
            int mid2 = left - mid1;// taking mid2 element from num2 on left
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;// default values
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            // check the conditions
            if(l1 <= r2 && l2 <= r1){
                l = max(l1, l2);
                r = min(r1, r2);
                if((n1 + n2) % 2)
                    return l;
                else
                    return (l + r) / 2.0;
            }else if(l1 > r2)
                    high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    } 
};