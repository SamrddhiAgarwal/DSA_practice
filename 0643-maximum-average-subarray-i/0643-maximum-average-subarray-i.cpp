class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double s=0.0;
        for(int i=0;i<k;i++)
        {
            s+=nums[i];
        }
        double avg=s/k;
        int j=0;
        double mx=avg;
        int n=nums.size();
        for(int i=k;i<n;i++)
        {
            s=s-nums[j]+nums[i];
            avg=s/k;
            mx=max(mx,avg);
            j++;
        }
        return mx;
    }
};