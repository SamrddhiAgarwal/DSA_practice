class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && dq.front()<nums[i])
            dq.pop_front();

            dq.push_front(nums[i]);
        }
        vector<int> ans;
        ans.push_back(dq.back());
        int j=0;int n=nums.size();
        for(int i=k;i<n;i++)
        {
            while(!dq.empty() && dq.front()<nums[i])
            dq.pop_front();

            dq.push_front(nums[i]);
        
            if(dq.back()==nums[j])
            {
                dq.pop_back();
            }
            j++;
            ans.push_back(dq.back());
        }
        return ans;
    }
};