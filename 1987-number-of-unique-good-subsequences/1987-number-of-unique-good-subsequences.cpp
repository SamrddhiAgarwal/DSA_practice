class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n=binary.size();
        long long ending_with_one=0;
        long long ending_with_zero=0;
        bool has_zero=false;
        long long MOD=1e9+7;
        for(auto& c:binary)
        {
            if(c=='1')
            {
                ending_with_one=(ending_with_one+ending_with_zero+1)%MOD;
            }
            else
            {
                ending_with_zero=(ending_with_one+ending_with_zero)%MOD;
                has_zero=true;
            }
        }
        long long total = (ending_with_one + ending_with_zero + (has_zero ? 1 : 0)) % MOD;
        
        return total;
    }
};