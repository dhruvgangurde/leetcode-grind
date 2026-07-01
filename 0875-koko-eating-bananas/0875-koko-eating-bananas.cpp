class Solution {
public:

    int maxElement(vector <int> & piles)
    {
        int max=0;
        for(int ele : piles)
        {
            if (ele>max) max=ele;
        }
        return max;
    }

    bool isValid(vector <int>& piles, int k,int h)
    {
        long long hrs=0;
        for ( int x : piles)
        {
            hrs+=(x+k-1)/k;
        }
        if(hrs<=h)
        {
            return true;
        }
        return false;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = maxElement(piles);
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(piles,mid,h))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return ans;
    }

};