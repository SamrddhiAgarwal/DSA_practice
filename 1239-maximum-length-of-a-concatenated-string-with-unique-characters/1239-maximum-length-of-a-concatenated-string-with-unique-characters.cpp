class Solution {
public:
    int ans;
    void helper(int i,int mask,int len,vector<pair<int,int>>&all_mask)
    {
        if(i==all_mask.size())
        {
            ans=max(ans,len);
            return;
        }

        int nextmask=all_mask[i].first;
        int nextlen=all_mask[i].second;
        if((mask & nextmask) == 0)
        {
            // mask|=nextmask;
            // len+=nextlen;
            helper(i+1,mask|nextmask,len+nextlen,all_mask);
        }

        helper(i+1,mask,len,all_mask);

        
    }
    int maxLength(vector<string>& arr) {
        vector<pair<int,int>>all_mask;
        for(auto s:arr)
        {
            int mask=0;
            bool isValid=true;
            for(auto c:s)
            {
                int bit=c-'a';
                // if(mask & (1<<bit) !=0)  this is read as mask & ((1<<bit)!=0)
                if((mask & (1<<bit)) !=0) 
                {
                    isValid=false;
                    break;
                }
                mask|=(1<<bit);
            }
            if(isValid)
            {
                all_mask.push_back({mask,__builtin_popcount(mask)});
            }
        }
        ans=0;
        helper(0,0,0,all_mask);
        return ans;
    }
};




// class Solution {
// public:
//     int maxLength(vector<string>& arr) {
//         int n=arr.size();
//         vector<int> bitmask(n+1,0);
//         int j=1;
//         for(auto &s:arr)
//         {
//             n=s.size();
//             int mask=0,i=0;
//             while(i<n)
//             {
//                 mask+=1<<(s[i]-'a');
//                 i++;
//             }
//             bitmask[j++]=mask;
//         }

//         vector<int>dp(n+1,0),curr(n+1,0);
//         for(int j=1;j<=26;j++)
//         {
                
//             for(int i=1;i<n+1;i++)
//             {
//                 int take=0,not_take=0;
//                 if((dp[i-1] & bitmask[i]) == 0)
//                 take=dp[i-1] | bitmask[i];
//                 else
//                 {

//                     if(__builtin_popcount(dp[i])>__builtin_popcount(curr[i-1]))
//                     not_take=dp[i];
//                     else
//                     not_take=curr[i-1];
//                 }
//                 curr[i]=(__builtin_popcount(take)>__builtin_popcount(not_take))? take:not_take;

//             }
//             dp=curr;
//         }
//         return dp[n];
//     }
// };