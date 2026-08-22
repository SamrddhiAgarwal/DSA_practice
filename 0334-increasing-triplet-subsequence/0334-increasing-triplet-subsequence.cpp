class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn=INT_MAX,smn=INT_MAX;
        for(auto & n:nums)
        {
            if(n<=mn)
            mn=n;
            else if(mn<n && n<=smn)
            smn=n;
            else
            return true;
        }
        return false;
    }
};