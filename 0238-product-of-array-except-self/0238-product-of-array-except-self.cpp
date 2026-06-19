class Solution {
public:
    //method-1 using cnt for 0
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> v(n,1);
    //     vector<int> right(n,1);
    //     int pro,cnt;
    //     if(nums[0]==0)
    //     {
    //         pro=1;
    //         cnt=1;
    //     }
    //     else
    //     {
    //         pro=nums[0];
    //         cnt=0;
    //     }
    //     for(int i=1;i<n;i++)
    //     {
    //         v[i]=v[i-1]*nums[i-1];
    //         if(nums[i]==0)
    //         {
    //             cnt++;
    //             continue;
    //         }
    //         pro=pro*nums[i];
    //     }
    //     for(int i=n-2;i>=0;i--)
    //     {
    //         if(nums[i]!=0)
    //         v[i]=v[i+1]*nums[i+1]/nums[i];
    //         else
    //         {
    //             if(cnt<=1)
    //             v[i]=pro;
    //             else
    //             v[i]=0;
    //         }
    //     }
    //     return v;
    // }
    //method-2 using 2 vector
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> v(n,1);
    //     vector<int> right(n,1);
        
    //     for(int i=1;i<n;i++)
    //     {
    //         v[i]=v[i-1]*nums[i-1];
    //     }
    //     for(int i=n-2;i>=0;i--)
    //     {
    //         right[i]=right[i+1]*nums[i+1];
    //         v[i]=v[i]*right[i];
    //     }
    //     return v;
        
    // }
    //method -3 using cnt for 0 another method
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> v;int s=0; int pro=1;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(nums[i]==0)
    //         {
    //             s++;
    //             continue;
    //         }
    //         pro=pro*nums[i];
    //     }
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(s==1 )
    //         {
    //             if(nums[i]==0)
    //             v.push_back(pro);
    //             else
    //             v.push_back(0);
    //         }
    //         else if(s>1)
    //         v.push_back(0);
    //         else{
    //             int a = pro/nums[i];
    //             v.push_back(a);
    //         }
    //     }
    //     return v;
    // }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <int>v(n,1);
        for(int i=1;i<nums.size();i++)
        {
            v[i]=v[i-1]*nums[i-1];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--)
        {
            v[i]=v[i]*suffix;
            suffix=suffix*nums[i];
        }
        return v;
    }
};