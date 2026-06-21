class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     int cnt=0,a;
    //     for(auto& n:nums)
    //     {
    //         if(cnt==0)
    //         {
    //             a=n;
    //             cnt=1;
    //         }
    //         else if(n==a)
    //         {
    //             cnt++;
    //         }
    //         else
    //         {
    //             cnt--;
    //         }
    //     }
    //     int cnt2=0;
    //     for(auto& n:nums)
    //     {
    //         if(a==n)
    //         cnt2++;
    //     }
    //     if(cnt2 > nums.size()/2)
    //     return a;
    //     return -1;
        
    // }
    int majorityElement(vector<int>& nums) {
        int len=32,ans=0;;
        for(int i=0;i<len;i++)
        {
            int cnt=0;
            for(auto n:nums)
            {
                if(n & (1<<i))
                cnt++;
            }
            if(cnt>nums.size()/2)
            ans+=(1<<i);
        }
        return ans;
    }
};