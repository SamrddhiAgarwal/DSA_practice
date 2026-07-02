class Solution {
public:
    long long helper(vector<int>& piles,int k)
    {
        long long day=0;
        for(auto &n:piles)
        {
            if(n%k!=0) day+=(n/k)+1;
            else day+=n/k;
        }
        return day;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high,low=1;
        high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long  ans=helper(piles,mid);
            // return ans;
            if(ans<=h)
            {
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
        }
        return low;
    }
};