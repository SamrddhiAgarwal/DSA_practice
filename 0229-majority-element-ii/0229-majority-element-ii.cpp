class Solution {
public:
    // vector<int> majorityElement(vector<int>& nums) {
    //     int c1=-1,c2=-1,a,b;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         if(c1==0)
    //         {
    //             if(nums[i]!=b)
    //             {
    //                 c1=1;
    //                 a=nums[i];
    //             }
    //         }
    //         else if(c2==0)
    //         {
    //             if(nums[i]!=a)
    //             {
    //                 c2=1;
    //                 b=nums[i];
    //             }
    //         }
    //         else if(c1==-1)
    //         {
    //             c1=1;
    //             a=nums[i];
    //         }
    //         else if(nums[i]==a)
    //         {
    //             c1++;
    //         }
    //         else if(c2==-1)
    //         {
    //             c2=1;
    //             b=nums[i];
    //         }
    //         else if(nums[i]==b)
    //         {
    //             c2++;
    //         }
    //         else
    //         {
    //             c2--;
    //             c1--;
    //         }
            
    //     }
    //     int cnt1=0,cnt2=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i]==a) cnt1++;
    //         if(nums[i]==b) cnt2++;
    //     }
    //     vector<int> ans;
    //     if(cnt1>n/3) ans.push_back(a);
    //     if(cnt2>n/3 && b!=a) ans.push_back(b);
    //     return ans;
    // }
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,a=INT_MIN,b=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(c1==0 && nums[i]!=b)
            {
                
                c1=1;
                a=nums[i];
            }
            else if(c2==0 && nums[i]!=a)
            {
                c2=1;
                b=nums[i];
            }
            else if(nums[i]==a)
            {
                c1++;
            }
            else if(nums[i]==b)
            {
                c2++;
            }
            else
            {
                c2--;
                c1--;
            }
            
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==a) cnt1++;
            if(nums[i]==b) cnt2++;
        }
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(a);
        if(cnt2>n/3 && b!=a) ans.push_back(b);
        return ans;
    }
};