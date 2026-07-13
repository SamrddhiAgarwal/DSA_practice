class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        int mx=*(max_element(nums.begin(),nums.end()));
        vector<int> cumFreq(mx+k+1,0);
        for(int i=0;i<n;i++)
        {
            cumFreq[nums[i]]++;
        }

        for(int i=1;i<mx+k+1;i++)
        {
            cumFreq[i]=cumFreq[i]+cumFreq[i-1];
        }

        int ans=0;
        // for(int i=0;i<mx+1;i++)
        // {
        //     if(cumFreq[i]==0) continue;
        //     int possFreq,freq;
        //     if (i-1>=0)
        //     freq=cumFreq[i]-cumFreq[i-1];
        //     else 
        //     freq=cumFreq[i];
        //     // if(i-k-1>=0 && i+k<mx+k+1)
        //     if(i-k-1>=0)
        //     possFreq=cumFreq[i+k]-cumFreq[i-k-1];
        //     // else if(i+k<mx+k+1)
        //     else
        //     possFreq=cumFreq[i+k];

        //     int maxOperations=min(possFreq-freq,numOperations);
        //     ans=max(ans,maxOperations+freq);
        // }
        for(int target=0; target<mx+k+1; target++){
            // if(cumFreq[target]==0)
            //     continue;
            
            int left=max(0,target-k);
            int right=min(mx+k,target+k);

            int total=cumFreq[right]-(left>0?cumFreq[left-1]:0);
            int target_count=cumFreq[target]-(target>0?cumFreq[target-1]:0);

            int need=total-target_count;
            int freq=target_count+min(need,numOperations);

            ans=max(ans,freq);
        }
        return ans;
    }
};