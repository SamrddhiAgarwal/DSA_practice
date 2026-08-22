class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos=0,neg=0,len=0;
        for(auto &num:nums)
        {
            if(num==0)
            {
                pos=0;
                neg=0;
            }
            else if(num>0)
            {
                pos++;
                neg=neg!=0? neg+1:0;
            }
            else
            {
                int temp=pos;
                pos = neg!=0? neg+1:0;
                neg=temp+1;
            }
            len=max(len,pos);
        }
        return len;
    }
};
// class Solution {
// public:
//     int getMaxLen(vector<int>& nums) {
//         int first=0,last=0,cnt=0,len=0,j=0,n=nums.size();
//         for(int i=0;i<=n;i++)
//         {
//             if(i<n && nums[i]<0)
//             {
//                 cnt++;
//                 if(cnt==1)
//                 first=i;
//                 last=i;
//             }
//             if(i==n || nums[i]==0 )
//             {
//                 if (cnt%2==0)
//                 len=max(len,i-j);
//                 else
//                 {
//                     len=max(len,i-first-1);
//                     len=max(len,last-j);
//                 }
                
//                 j=i+1;
//                 cnt=0;
//             }
//         }
//         return len;
//     }
// };