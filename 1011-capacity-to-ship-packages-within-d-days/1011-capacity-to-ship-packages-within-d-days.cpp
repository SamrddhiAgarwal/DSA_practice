class Solution {
public:
    bool possible(vector<int>& arr, int n, int d, int wc)
    {
        int k=0,dp=1;
        for(int i=0;i<n;i++)
        {
            k=k+arr[i];
            if(k>wc)
            {
                k=arr[i];
                dp++;
            }
        }
        
        
        if(dp<=d) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0,low=INT_MIN,mid,n=weights.size();
        for(int i=0;i<n;i++)
        {
            high=high+weights[i];
            low=max(low,weights[i]);
        }
        
        //we are taking max in low cause we have to take one segment at a time
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(possible(weights,n,days,mid))
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
     
};