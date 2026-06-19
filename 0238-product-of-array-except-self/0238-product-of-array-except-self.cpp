class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,1);
        vector<int> right(n,1);
        int pro,cnt;
        if(nums[0]==0)
        {
            pro=1;
            cnt=1;
        }
        else
        {
            pro=nums[0];
            cnt=0;
        }
        for(int i=1;i<n;i++)
        {
            v[i]=v[i-1]*nums[i-1];
            if(nums[i]==0)
            {
                cnt++;
                continue;
            }
            pro=pro*nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]!=0)
            v[i]=v[i+1]*nums[i+1]/nums[i];
            else
            {
                if(cnt<=1)
                v[i]=pro;
                else
                v[i]=0;
            }
        }
        return v;
    }
};