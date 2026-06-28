class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long mx=LLONG_MIN;
        long long smx=LLONG_MIN;
        long long tmx=LLONG_MIN;

        for(auto n:nums)
        {
            if(n>mx)
            {
                tmx=smx;
                smx=mx;
                mx=n;
            }
            else if(n<mx && n>smx)
            {
                tmx=smx;
                smx=n;
            }
            else if(n<smx && n>tmx)
            {
                tmx=n;
            }
        }
        return tmx!=LLONG_MIN? tmx:mx;
    }
};