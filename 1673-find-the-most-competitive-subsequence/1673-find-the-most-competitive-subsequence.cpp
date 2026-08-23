class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // deque<int>dq;
        // stack<int>dq;
        vector<int>dq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            
            while(!dq.empty() && dq.back()>nums[i] && dq.size()+n-i>k)
            {
                dq.pop_back();
            }
            if(dq.size()<k) dq.push_back(nums[i]);
            
        }
        vector<int>ans(k,0);
        // while(!dq.empty() && dq.size()> k)
        // {
        //     dq.pop_back();
        // }  instead we use condition above 
        return dq;
        // while(!dq.empty())
        // {
        //     ans[k-1]=dq.top();
        //     dq.pop();
        //     k--;
        // }
        // return ans;
    }
};